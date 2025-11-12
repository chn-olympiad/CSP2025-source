#include<bits/stdc++.h>
using namespace std;
const int N=1e6+50,Mod=1e9+7;
const int H1=13,H2=131;
int n,q;
string s1[N],s2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		
	}
	for(int i=1;i<=q;i++){
		string t1,t2;cin>>t1>>t2;
		int ans=0;
		for(int i=1;i<=t1.size();i++){
			for(int j=1;j<=n;j++){
				if(s1[j].size()>i)continue;
				string a=t1.substr(i-s1[j].size(),s1[j].size());
				if(a!=s1[j])continue;
				string b=t1.substr(0,i-s1[j].size());
				string c=t1.substr(i,t1.size()-i);
				string tmp=b+s2[j]+c;
				if(tmp==t2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
