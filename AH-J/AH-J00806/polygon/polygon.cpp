#include<bits/stdc++.h>
using namespace std;
int a[5010],b[5010],c[5010],d[5010],vis[5010];
long long m;
int n;
map<string,int>mp;
void dfs(int x,int cnt,long long ans,int maxn){
	if(cnt>=3){
		string s="";
		long long t=1;
		for(int i=0;i<cnt;i++){
			s+=to_string(b[i]);
			d[b[i]]++;
		}
		for(int i=0;i<cnt;i++){
			if(!vis[b[i]]){
				vis[b[i]]=1;
				long long t1=1,t2=1;
				for(int j=c[b[i]];j>=1;j--){
					t1*=j; 
				}
				for(int j=d[b[i]];j>=1;j--){
					t2*=j; 
				}
				t=(t*t1/t2)%998244353;
			}
		}
		memset(d,0,sizeof(d));
		memset(vis,0,sizeof(vis));
		if(mp[s]==0){
			mp[s]++;
			if(ans>maxn*2){
			//	cout<<"hehe "<<s<<" "<<t<<endl;
				m+=t;
			}
			m%=998244353;
		}
	}
	if(x==n+1) return;
	b[cnt]=a[x];
	dfs(x+1,cnt+1,ans+a[x],a[x]);
	dfs(x+1,cnt,ans,maxn);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}else if(n==3){
		int u,v,w;
		cin>>u>>v>>w;
		int x=max(max(u,v),max(v,w));
		if(x*2<u+v+w) cout<<1;
		else cout<<0;
		return 0;
	}else{
		int TF=1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]!=1) TF=0;
			c[a[i]]++;
		}
		if(TF==1){
			long long ansx=0,xx=1,xxx=1;
			for(int i=1;i<=n;i++){
				xx*=i;
			}
			for(int i=3;i<=n;i++){
				for(int j=1;j<=i;j++){
					xxx*=j;
				}
				ansx+=xx/xxx;
			}
			cout<<ansx%998244353;
			return 0;
		}
		sort(a+1,a+1+n);
		dfs(1,0,0,0);
		cout<<m;
	}
	return 0;
}
