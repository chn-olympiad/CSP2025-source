#include<bits/stdc++.h>
using namespace std;
long long t,n,maxx=0,ans=0;
long long ja=0,jb=0,jc=0,flagc=0,flagb=0;
//long long a[100005],b[10005],c[100005];
struct sd{
	long long a,b,c;
};
sd h[100005];
int cmp(sd e,sd f){
	if(e.a>f.a)return 1;
	else if(e.a<f.a)return 0;
	else {
		if(e.b>=f.b)return 1;
		else if(e.b<f.b)return 0;
	}
}
void dfs(long long sum,long long io){
	if(sum>maxx)maxx=sum;
	if(io>n)return ;
	if(ja<n/2){
		ja++;
		dfs(sum+h[io].a,io+1);
		ja--;
	}
	if(jb<n/2){
		jb++;
		dfs(sum+h[io].b,io+1);
		jb--;
	}
	if(jc<n/2){
		jc++;
		dfs(sum+h[io].c,io+1);
		jc--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
		maxx=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>h[i].a>>h[i].b>>h[i].c;
			if(h[i].c!=0)flagc=1;
			if(h[i].b!=0)flagb=1;
		}
		if(n<=10){
			dfs(0,1);
			cout<<maxx<<"\n";
		}
		else if(flagc==0,flagb==0){
			int u=n/2;
			sort(h+1,h+n+1,cmp);
			for(int i=1;i<=n;i++){
				if(i<=u)ans+=h[i].a;
				else{
					ans+=h[i].b;
				}
			}
			cout<<ans<<"\n";
		}
		else if(flagc==0 and flagb==1){
			
		}
	}
	return 0;
}
