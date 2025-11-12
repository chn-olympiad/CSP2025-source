#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+10,M=2e6+10;
int n,m,k,f[N+10];
ll c[20],a[20][N+10],ans=1ll<<60;
struct st{
	int u,v;
	ll w;
}t[M+10];
bool cmp(st x,st y){
	return x.w<y.w;
}
ll ask(int u){
	if(f[u]==u){
		return u;
	}
	else{
		f[u]=ask(f[u]);
		return f[u];
	}
}
ll Find(int m){
	for(int i=1;i<=n+m;i++){
		f[i]=i;
	}
	int cnt=0,i=1;
	ll sum=0;
	while(cnt<n-1){
		if(ask(t[i].u)!=ask(t[i].v)){
			cnt++;
			if((f[t[i].u]==t[i].u&&f[t[i].v]==t[i].v&&((t[i].u)>n||(t[i].v)>n))||((t[i].u)>n&&(t[i].v)>n)){
				cnt--;
			}
			f[t[i].u]=t[i].v;
			sum+=t[i].w;
		}
		i++;
	}
	return sum;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0); 
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>t[i].u>>t[i].v>>t[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(k==0){
		sort(t+1,t+1+m,cmp);
		cout<<Find(0);
	}
	else if(k<=5&&m<=1e5){
		for(int i=0;i<(1<<k);i++){
			int j=i,cnt=0,p=0;
			ll sum=0;
			while(j){
				p++;
				if(j%2==1){
					cnt++;
					sum+=c[p];
					for(int j=1;j<=n;j++){
						t[(cnt-1)*n+m+j].u=n+cnt;
						t[(cnt-1)*n+m+j].v=j;
						t[(cnt-1)*n+m+j].w=a[p][j];
					}
				}
				j/=2;
			}
			sort(t+1,t+1+m+cnt*n,cmp);
			ans=min(ans,Find(cnt)+sum);
		}
		cout<<ans;
	}
	else{
		int x=m;
		for(int i=n+1;i<=n+k;i++){
			for(int j=1;j<=n;j++){
				t[++x].u=i;
				t[x].v=j;
				t[x].w=a[i-n][j];
			}
		}
		sort(t+1,t+1+m+k*n,cmp);
		cout<<Find(k);
	}
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

13

6 5 0
1 2 8
1 3 7
1 4 6
1 5 5
1 6 4

30
*/
