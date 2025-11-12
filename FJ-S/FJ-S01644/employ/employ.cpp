#include<bits/stdc++.h>
using namespace std;
int a[1005];
int x[1005];
int p[100005];
int c[10005];
int d[10005];
int n,m;
long long r;
int mod=998244353;
void dfs(int k){
	if(k>n){
		int z=0,w=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				if(x[c[i]]<=z){
					continue;
				}else{
					w++;
				}
			}else{
				z++;
			}
		}
		if(w>=m)r+=1;
		
		return;
	}
	for(int i=1;i<=n;i++){
		if(d[i]==0){
			d[i]=1;
			c[k]=i;
			dfs(k+1);
			d[i]=0;
		}
	}
} 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	string k;
	cin>>k;
	int f=0;
	for(int i=0;i<k.size();i++){
		if(k[i]=='0')a[i+1]=0;
		else a[i+1]=1,f++;	
	}
	for(int i=1;i<=n;i++){ 
		scanf("%d",&x[i]);
	}
	sort(x+1,x+n+1);
	for(int i=1;i<=n;i++){
		p[x[i]]=i;
	}
	long long s=n-p[0];
	int t=0;
	if(s<m||f<m){
		cout<<0;
		return 0;
	}
	dfs(1);
	printf("%lld",r);
}
