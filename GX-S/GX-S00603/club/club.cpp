#include<bits/stdc++.h>
using namespace std;
long long T,n,a[100050][3],b[100005][2];
long long sum=0;
struct node{
	long long w,v; 
}c[100005];
bool cmp(node g,node h){
	return g.w<h.w;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		sum=0;
		int x=0,y=0,z=0;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i][0],&a[i][1],&a[i][2]);
			if(a[i][0]>=max(a[i][1],a[i][2])){
				b[i][0]=a[i][0],b[i][1]=0;
				x++;
				sum+=b[i][0];
				continue;
			}
			if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
				b[i][0]=a[i][1],b[i][1]=1;
				y++;
				sum+=b[i][0];
				continue;
			}
			if(a[i][2]>=a[i][0]&&a[i][2]>=a[i][1]){
				b[i][0]=a[i][2],b[i][1]=2;
				z++;
				sum+=b[i][0];
				continue;
			}
		}int p=n/2;
		if(x<=p&&y<=p&&z<=p){
			cout<<sum<<endl;
			continue;
		}
		else{
			int u=0,cnt=0;
			if(x>p)u=0;
			if(y>p)u=1;
			if(z>p)u=2;
			for(int i=1;i<=n;i++){
				if(b[i][1]==u){
					int q;
					if(u==0) q=max(a[i][1],a[i][2]);
					if(u==1) q=max(a[i][0],a[i][2]);
					if(u==2) q=max(a[i][0],a[i][1]);
					c[++cnt].w=b[i][0]-q;
				}
			}
			sort(c+1,c+cnt+1,cmp);
			for(int i=1;i<=cnt-p;i++){
				sum=sum-c[i].w;
			}
			cout<<sum<<endl;
		}
	}
	return 0;
}
