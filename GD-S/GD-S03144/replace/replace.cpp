#include<bits/stdc++.h>
using namespace std;
int n,q,f1[5000005],f2[5000005];
string s1[5000005],s2[5000005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		f1[i]=f2[i]=-1;
		for(int j=0;j<s1[i].size();j++){
			if(s1[i][j]=='b')f1[i]=j;
		}
		for(int j=0;j<s2[i].size();j++){
			if(s2[i][j]=='b')f2[i]=j;
		}
		if(f1[i]==-1||f2[i]==-1){
			while(q--){
				cout<<0<<'\n';
			}
			exit(0);
		}
	}
	while(q--){
		string s,t;
		cin>>s>>t;
		int a=-1,b=-1;
		for(int i=0;i<s.size();i++){
			if(s[i]=='b')a=i;
		}
		for(int i=0;i<t.size();i++){
			if(t[i]=='b')b=i;
		}
		if(a==-1||b==-1){
			cout<<0<<'\n';
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			//cerr<<(s1[i].size()-f1[i]-1>s.size()-a-1)<<' '<<(s2[i].size()-f2[i]-1>t.size()-b-1)<<' '<<(s.size()-s1[i].size()+s2[i].size()!=t.size())<<'\n';
			if(f1[i]>a||f2[i]>b||s1[i].size()-f1[i]-1>s.size()-a-1||s2[i].size()-f2[i]-1>t.size()-b-1||s.size()-s1[i].size()+s2[i].size()!=t.size())continue;
			ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
1 2
aabaa baaaa
aaaba abaaa
aaabaa abaaaa
*/
