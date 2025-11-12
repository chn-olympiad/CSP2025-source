#include<bits/stdc++.h>
using namespace std;
int t,n,ano[100005],top,ans;
struct node{
	int m[4],maxn,minn,h,dt;
}a[100005];
bool cmp(node x,node y){
	if(x.dt==y.dt){
		return x.maxn>y.maxn;
	}else{
		return x.dt>y.dt;
	}
}
void slove(){
	ans=0;
	cin>>n;
	top=0;
	int c[4];
	c[1]=c[2]=c[3]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].m[1]>>a[i].m[2]>>a[i].m[3];
		a[i].maxn=max(a[i].m[1],max(a[i].m[2],a[i].m[3]));
		//a[i].dt=min(a[i].maxn-a[i].m[1],min(a[i].maxn-a[i].m[2],a[i].maxn-a[i].m[3]));
		a[i].dt=1145141919;
		for(int j=1;j<=3;j++){
			if(a[i].maxn!=a[i].m[j]){
				a[i].dt=min(a[i].maxn-a[i].m[j],a[i].dt);
			}
		}
		//cout<<a[i].dt<<"\n";
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		bool flag=0;
		for(int j=1;j<=3;j++){
			if(a[i].maxn==a[i].m[j]&&!flag){
				if(c[j]>=(n/2)){
					ans=ans+a[i].maxn-a[i].dt;
				}else{
					c[j]++;
					ans+=a[i].maxn;
				}
				flag=1;
			}
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		slove();
	}
} 
