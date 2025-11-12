#include<bits/stdc++.h>
using namespace std;

struct N{
	long long a,b,c,i;
}a[100010],b[100010];	
long long n,t;
bool cmp(N x,N y){
	return x.a>y.a;
}
bool cmp1(N x,N y){
	return x.b>y.b;
}
long long ans=0;
void dfs(long long id,long long sum,long long x,long long y,long long z){
	if(id==n){
		ans=max(ans,sum);
		return;
	}
	if(x<n/2)dfs(id+1,sum+a[id+1].a,x+1,y,z);
	if(y<n/2)dfs(id+1,sum+a[id+1].b,x,y+1,z);
	if(z<n/2)dfs(id+1,sum+a[id+1].c,x,y,z+1);
	return;
}
long long cnt;
void dfs1(long long id,long long sum,long long x,long long y){
	cnt++;
	if(cnt>=1e8/1.9) return;
	if(id==n){
		ans=max(ans,sum);
		return;
	}
	if(x>y){
		if(y<n/2)dfs1(id+1,sum+a[id+1].b,x,y+1);
		if(x<n/2)dfs1(id+1,sum+a[id+1].a,x+1,y);
	}
	else{
		if(x<n/2)dfs1(id+1,sum+a[id+1].a,x+1,y);
		if(y<n/2)dfs1(id+1,sum+a[id+1].b,x,y+1);
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		bool f1=1,f2=1;
		for(int i=1;i<=n;i++){
			N x;
			cin>>x.a>>x.b>>x.c;
			x.i=i;
			a[i]=x;
			b[i]=x;
			if(x.b!=0||x.c!=0) f1=0;
			if(x.c!=0) f2=0;
		}
		if(f1){
			sort(a+1,a+n+1,cmp);
			long long sum=0;
			for(int i=1;i<=n/2;i++){
				sum+=a[i].a;
			}
			cout<<sum<<'\n';
		}
		if(f2){
//			sort(a+1,a+n+1,cmp);
//			sort(b+1,b+n+1,cmp1);
//			long long sum1=0,sum2=0;
//			for(int i=1;i<=n/2;i++){
//				sum1+=a[i].a;
//				sum1+=a[n-i+1].b;
//			}
//			for(int i=1;i<=n/2;i++){
//				sum2+=b[i].b;
//				sum2+=b[n-i+1].a;
//			}
//			cout<<max(sum1,sum2)<<'\n';
			ans=0;
			cnt=0;
			dfs1(0,0,0,0);
			cout<<ans<<'\n';
		}
		else if(n<=30){
			ans=0;
			cnt=0;
			dfs(0,0,0,0,0);
			cout<<ans<<'\n';
		}else{
			
		}
	}
	return 0;
}
/*
1
8
0 1 0
0 2 0
0 3 0
0 4 0
0 5 0
0 6 0
0 8 0
0 0 0

*/