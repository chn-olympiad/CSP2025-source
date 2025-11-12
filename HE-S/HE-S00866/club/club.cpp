#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,t,c1,c2,c3,c4;
struct st{
	long long v,i;
};
st d1[N],d2[N],d3[N];
long long d4[N];
int a[N][5];
bool cmp(st x,st y){
	return (x.v>y.v)||(x.v==y.v&&x.i<y.i);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		c1=0;
		c2=0;
		c3=0;
		c4=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
			}
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				d1[++c1]={a[i][1],i};
			}else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				d2[++c2]={a[i][2],i};
			}else{
				d3[++c3]={a[i][3],i};
			}
		}
		sort(d1+1,d1+c1+1,cmp);
		sort(d2+1,d2+c2+1,cmp);
		sort(d3+1,d3+c3+1,cmp);
		long long ans=0,cnt=0;
		for(int i=1;i<=c1;i++){
			ans+=d1[i].v;
		}
		for(int i=1;i<=c2;i++){
			ans+=d2[i].v;
		}
		for(int i=1;i<=c3;i++){
			ans+=d3[i].v;
		}
		if(c1>n/2){
			for(int i=1;i<=c1;i++){
				int id=d1[i].i;
				if(a[id][2]>a[id][3]){
					d4[++c4]=d1[i].v-a[id][2];
				}else{
					d4[++c4]=d1[i].v-a[id][3];
				}
			}
			cnt=c1;
		}else if(c2>n/2){
			for(int i=1;i<=c2;i++){
				int id=d2[i].i;
				if(a[id][1]>a[id][3]){
					d4[++c4]=d2[i].v-a[id][1];
				}else{
					d4[++c4]=d2[i].v-a[id][3];
				}
			}
			cnt=c2;
		}else if(c3>n/2){
			for(int i=1;i<=c3;i++){
				int id=d3[i].i;
				if(a[id][2]>a[id][1]){
					d4[++c4]=d3[i].v-a[id][2];
				}else{
					d4[++c4]=d3[i].v-a[id][1];
				}
			}
			cnt=c3;
		}
		sort(d4+1,d4+c4+1);
		for(int i=1;i<=cnt-n/2;i++){
			ans-=d4[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
