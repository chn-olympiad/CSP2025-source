#include<bits/stdc++.h>
using namespace std;

const int N=100005;

struct node{
	int a1,a2,a3,m;
};

int T,n,ans,ma[6],m;
node a[N],b[N];

bool cmp(node x,node y){
	return x.m>=y.m;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.ans","w",stdout);
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		scanf("%d",&n);
		ans=0;
		ma[1]=0;ma[2]=0;ma[3]=0; 
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&(a[i].a1),&(a[i].a2),&(a[i].a3));
			if(a[i].a1>=a[i].a2&&a[i].a1>=a[i].a3){
				ma[1]++;
				a[i].m=1;
			}
			else if(a[i].a2>=a[i].a1&&a[i].a2>=a[i].a3){
				ma[2]++;
				a[i].m=2;
			}
			else{
				ma[3]++;
				a[i].m=3;
			}
		}
		if(ma[1]>=ma[2]&&ma[1]>=ma[3]) m=1;
		else if(ma[2]>=ma[1]&&ma[2]>=ma[3]) m=2;
		else m=3;
		//printf("!! %d %d %d %d\n",m,ma[1],ma[2],ma[3]);
		if(ma[m]<=n/2){
			for(int i=1;i<=n;i++){
				if(a[i].m==1) ans+=a[i].a1;
				else if(a[i].m==2) ans+=a[i].a2;
				else ans+=a[i].a3;
			}
		}
		else{
			if(m==1){
				for(int i=1;i<=n;i++){
					b[i].a1=a[i].a1;
					b[i].a2=max(a[i].a2,a[i].a3);
				}
			}
			else if(m==2){
				for(int i=1;i<=n;i++){
					b[i].a1=a[i].a2;
					b[i].a2=max(a[i].a1,a[i].a3);
				}
			}
			else{
				for(int i=1;i<=n;i++){
					b[i].a1=a[i].a3;
					b[i].a2=max(a[i].a1,a[i].a2);
				}
			}
			for(int i=1;i<=n;i++){
				ans+=b[i].a2;
				b[i].m=b[i].a1-b[i].a2;
			}
			sort(b+1,b+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=b[i].m;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
