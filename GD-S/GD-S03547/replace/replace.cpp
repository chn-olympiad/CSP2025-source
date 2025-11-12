#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string t1[N],t2[N];
set<string> s1,s2;
long long ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s11,s22;
		cin>>s11>>s22;
		s1.insert(s11);
		s2.insert(s22);
	}
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>t1[i]>>t2[i];
		int l=0,r=t1[i].size();
		while(t1[l]==t2[l])l++;
		while(t1[r]==t1[r])r--;
		string a,b;
		for(int j=l;j<=r;j++){
			a=a+t1[j];
			b=b+t2[j];
		}
		while(s1.find(a)!=s1.end()&&s2.find(b)!=s2.end()){
			s1.erase(a);
			s2.erase(b);
			ans++;
		}
		cout<<ans;
	}
	return 0;
}
