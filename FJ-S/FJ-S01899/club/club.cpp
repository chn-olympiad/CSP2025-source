#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int b[N];
struct Node{
	int w,idx;
}a[N][5];
struct Node2{
	int aa,ab;
}c[N];
bool cmp1(Node x,Node y){
	return x.w>y.w;
}
bool cmp2(Node2 x,Node2 y){
	return (x.aa-x.ab)<(y.aa-y.ab);
}
int main(){
//	freopen("club5.in","r",stdin);
//	freopen("club1.out","w",stdout);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		int n,t=0,flag=1,cnt=0,ans=0;
		scanf("%d",&n);
		b[1]=b[2]=b[3]=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1].w,&a[i][2].w,&a[i][3].w);
			a[i][1].idx=1,a[i][2].idx=2,a[i][3].idx=3;
			sort(a[i]+1,a[i]+1+3,cmp1);
			ans+=a[i][1].w;
			int t=a[i][1].idx;
			b[t]++;
//			cout<<b[t]<<" ";
		}
		for(int i=1;i<=3;i++){
			if(b[i]>n/2){
				t=i;
				flag=0;
				break;
			}
		}
//		cout<<b[t]<<"\n";
		if(!flag){
			for(int i=1;i<=n;i++){
				if(a[i][1].idx==t){
					c[++cnt].aa=a[i][1].w;
					c[cnt].ab=a[i][2].w;
				}
			}
			sort(c+1,c+cnt+1,cmp2);
			for(int i=1;i<=(b[t]-n/2);i++){
				ans-=(c[i].aa-c[i].ab);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
} 
