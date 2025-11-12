#include<bits/stdc++.h>
using namespace std;
/*struct node{
	long long a,b,c,gx;
}k[100001];
/bool cmp(node x,node y){
	return x.gx<y.gx;
}*/
long long t,n,f[100001],a[100001],b[100001],c[100001],anss,xz,w1[100001],w2[100001],w3[100001];
long long js(long long sy1,long long sy2,long long sy3,long long ans1){
	if(sy1>n/2||sy2>n/2||sy3>n/2)return 0;
	if(sy1+sy2+sy3==n){
		if(sy1>n/2||sy2>n/2||sy3>n/2)return 0;
		else{
			return ans1;
		}
	}
	if(sy1>n/2||sy2>n/2||sy3>n/2)return 0;
	ans1=max(max(js(sy1+1,sy2,sy3,ans1+a[sy1+sy2+sy2+1]),js(sy1,sy2+1,sy3,ans1+b[sy1+sy2+sy2+1])),js(sy1,sy2,sy3+1,ans1+c[sy1+sy2+sy2+1]));
	if(sy1>n/2||sy2>n/2||sy3>n/2)return 0;
	return ans1;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(long long i=1;i<=t;i++){
		cin>>n;
		anss=0;
		xz=n/2;
		f[0]=1;
		for(long long j=1;j<=n;j++){
			cin>>a[j]>>b[j]>>c[j];//			k[j].gx=max(k[j].a,k[j].b,k[j].c);
			
		}if(n==2){
			anss=max(max(a[1]+c[2],max(b[1]+c[2],max(c[1]+a[2],max(b[1]+a[2],c[1]+b[2])))),a[1]+b[2]);
			cout<<anss<<"\n";
			continue;
		}
		
		if(n==4){
			anss=max(a[1]+a[2]+b[3]+b[4],max(a[1]+a[2]+b[3]+c[4],max(a[1]+a[2]+c[3]+c[4],max(a[1]+b[2]+b[3]+c[4],max(a[1]+b[2]+a[3]+b[4],a[1]+b[2]+a[3]+c[4])))));
		}
		long long ls=0,zs1=0,zs2=0,zs3=0;
		anss=js(0,0,0,0);
		cout<<anss<<"\n";
	}
	return 0;
}

