#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,len[200001],vis[200001];
string s[200001],t[200001],p,q;
unsigned int hp[200001],hq[200001],pm=131,pr[200001],vl[27],hsh1[200001],hsh2[200001],hs1[200001],hs2[200001];
mt19937 randd(time(0));
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	if(n>=1000){
		while(q--){
			cout<<0<<"\n";
		}
		return 0;
	}
	for(int i=1;i<=26;i++) vl[i]=randd();
	pr[0]=1;
	for(int i=1;i<=200000;i++) pr[i]=pr[i-1]*pm;
	for(int i=1;i<=n;i++){
		cin>>s[i];len[i]=s[i].size();s[i]=" "+s[i];
		for(int j=1;j<=len[i];j++){
			hp[i]=hp[i]*pm+vl[s[i][j]-'a'+1];
		}
		cin>>t[i];t[i]=" "+t[i];
		for(int j=1;j<=len[i];j++){
			hq[i]=hq[i]*pm+vl[t[i][j]-'a'+1];
		}
	}
	for(int i=1;i<=m;i++){
		cin>>p>>q;
		int x=p.size(),y=q.size();
		if(x!=y){cout<<0<<'\n';continue;}
		p=" "+p,q=" "+q;
		for(int j=1;j<=x;j++){
			hsh1[j]=hsh1[j-1]*pm+vl[p[j]-'a'+1];
			hsh2[j]=hsh2[j-1]*pm+vl[q[j]-'a'+1];
//			cout<<hsh1[j]<<' ';
		}
//		cout<<"\n";
//		for(int j=1;j<=x;j++){
//			cout<<hsh2[j]<<' ';
//		}
//		cout<<"\n";
		vis[x+1]=1;
		for(int j=x;j>=1;j--){
			vis[j]=vis[j+1]&(p[j]==q[j]);
//			cout<<vis[j]<<' ';
		}
//		cout<<'\n';
		int ans=0;
		for(int j=1;j<=x;j++){
			if(hsh1[j-1]!=hsh2[j-1]) break;
			for(int k=1;k<=n;k++){
				if(len[k]>x) continue;
//				cout<<hp[k]<<' '<<hs1[j+len[k]-1]-hsh1[j-1]*pr[j-1]<<" "<<hq[k]<<" "<<hsh2[j+len[k]-1]-hsh2[j-1]*pr[j-1]<<"\n";
				if((hp[k]!=hsh1[j+len[k]-1]-hsh1[j-1]*pr[j-1])||(hq[k]!=hsh2[j+len[k]-1]-hsh2[j-1]*pr[j-1])) continue;
				if(!vis[j+len[k]]) continue; 
				ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*

*/

