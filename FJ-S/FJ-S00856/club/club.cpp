#include<bits/stdc++.h>
using namespace std;
int t,n,club[4]={0,0,0,0};
long long ans[6];
struct people{
	int a;
	int b;
	int c;
	int a1;
	int b1;
	int c1;
}p[100001];
int max3(int x,int y,int z){
	if(x>=y&&x>=z) return x;
	if(y>=x&&y>=z) return y;
	if(z>=x&&z>=y) return z;
}
int max31(int x,int y,int z){
	if(x>=y&&x>=z) return 1;
	if(y>=x&&y>=z) return 2;
	if(z>=x&&z>=y) return 3;
}
int mid3(int x,int y,int z){
	if((x>=y&&x<=z)||(x<=y&&x>=z)) return x;
	if((y>=x&&y<=z)||(y<=x&&y>=z)) return y;
	if((z>=x&&z<=y)||(z<=x&&z>=y)) return z;
}
int mid31(int x,int y,int z){
	if((x>=y&&x<=z)||(x<=y&&x>=z)) return 1;
	if((y>=x&&y<=z)||(y<=x&&y>=z)) return 2;
	if((z>=x&&z<=y)||(z<=x&&z>=y)) return 3;
}
bool rule(people x,people y){
	return mid3(x.a1 ,x.b1 ,x.c1 )<mid3(y.a1 ,y.b1 ,y.c1 );
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int v=1;v<=t;v++){
		cin>>n;
		ans[v]=0;
		club[1]=club[2]=club[3]=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&p[i].a ,&p[i].b ,&p[i].c );
			int maxn=max3(p[i].a ,p[i].b ,p[i].c );
			p[i].a1 =p[i].a -maxn;
			p[i].b1 =p[i].b -maxn;
			p[i].c1 =p[i].c -maxn;
		}
		sort(p+1,p+n+1,rule);
//		for(int i=1;i<=n;i++){
//			cout<<p[i].a <<" "<<p[i].b<<" "<<p[i].c <<" "<<p[i].a1 <<" "<<p[i].b1 <<" "<<p[i].c1 <<endl; 
//		}
		for(int i=1;i<=n;i++){
			if(club[max31(p[i].a ,p[i].b ,p[i].c )]<n/2){
				club[max31(p[i].a ,p[i].b ,p[i].c )]++;
				ans[v]+=max3(p[i].a ,p[i].b ,p[i].c );
			}
			else{
				club[mid31(p[i].a ,p[i].b ,p[i].c )]++;
				ans[v]+=mid3(p[i].a ,p[i].b ,p[i].c );
			}
		}
	}
	for(int v=1;v<=t;v++) cout<<ans[v]<<endl;
	return 0;
}

