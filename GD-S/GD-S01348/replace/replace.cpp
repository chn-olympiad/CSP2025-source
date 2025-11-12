#include<iostream>
#include<cstdio>
#include<map>
#define ll long long
#define N 300010
#define MX 5000010
using namespace std;
map<string,map<string,int> >vis;
int n,q,ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	string s,t;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s>>t;
		vis[s][t]++;
	}
	while(q--){
		cin>>s>>t;
		ans=0;
		int m=s.size();
		int l=0,r=m-1;
		while(l<m-1&&s[l]==t[l])l++;
		while(r>0&&s[r]==t[r])r--;
		for(int i=l;i>=0;i--){
			string nws="",nwt="";
			for(int j=i;j<m;j++){
				nws+=s[j],nwt+=t[j];
				if(j>=r)ans+=vis[nws][nwt];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
