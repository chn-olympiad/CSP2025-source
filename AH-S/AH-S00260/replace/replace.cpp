#include<bits/stdc++.h>
using namespace std;
typedef pair<string,string> P;
typedef pair<int,int> p;
const int N=2e5+5;
int n,q,sum;
string s1[N],s2[N];
map<P,int> t;
int sol1(string t1,string t2){
	int ans=0,l=-1,r=t1.size();
	for(int i=0;i<t1.size();i++){
		if(t1[i]!=t2[i]) break;
		l=i;
	}
	for(int i=t2.size()-1;i>=0;i--){
		if(t1[i]!=t2[i]) break;
		r=i;
	}
	for(int i=0;i<=min(l+1,int(t1.size()-1));i++){
		string k1="",k2="";
		for(int j=i;j<max(i,r-1);j++){
			k1+=t1[j];
			k2+=t2[j];
		}
		for(int j=max(i,r-1);j<t2.size();j++){
			k1+=t1[j];
			k2+=t2[j];
			ans+=t[P(k1,k2)];
		}
	}
	return ans;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		sum+=s1[i].size();
		t[P(s1[i],s2[i])]++;
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		if(sum<=2000){
			cout<<sol1(t1,t2)<<"\n";
		}
	}
	return 0;
}
