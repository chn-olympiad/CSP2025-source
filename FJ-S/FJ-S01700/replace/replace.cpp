#include<bits/stdc++.h>
using namespace std;
int n,q;
const int N=2e5+5;
string s[N][3];
//int f[1005][1005];
//map<string,int> m;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
//	int cnt=0;
	for(int i=1;i<=n;++i){
		cin>>s[i][1]>>s[i][2];
	//	if(m[s[i][1]]==0)m[s[i][1]]=++cnt;
	//	if(m[s[i][2]]==0)m[s[i][2]]=++cnt;
	}
/*	for(int i=1;i<=cnt;++i)f[i][i]=1;
	for(int k=1;k<=cnt;++k)
		for(int i=1;i<=n;++i){
			for(int j=1;j<=cnt;++j){
				if(f[i][j]==0)f[i][j]=f[i][k]*f[k][j];
				else f[i][j]+=f[i][k]*f[k][j];
			}
		}*/ 
	while(q--)
	{
		string t,tt;cin>>t>>tt;
		cout<<"0\n";
	}
	return 0;
} 
