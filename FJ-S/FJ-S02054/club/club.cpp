#include<stdio.h>
#include<algorithm>
using namespace std;
typedef struct node{
	int num[4],d1,d2,id;
	int inx[4];
	friend bool operator<(node n1,node n2){
		return n1.d1>n2.d1||
		       n1.d1==n2.d1&&n1.num[1]>n2.num[1]||
			   n1.d1==n2.d1&&n1.num[1]==n2.num[1]&&n1.d2>n2.d2||
			   n1.d1==n2.d1&&n1.num[1]==n2.num[1]&&n1.d2==n2.d2&&n1.num[2]>n2.num[2]||
			   n1.d1==n2.d1&&n1.num[1]==n2.num[1]&&n1.d2==n2.d2&&n1.num[2]==n2.num[2]&&n1.num[3]>n2.num[3];
	}
}node;
struct node2{
	int a;
	int id;
	friend bool operator<(node2 n1,node2 n2){
		return n1.a>n2.a;
	}
}r[4];
node a[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		long long ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&r[1].a,&r[2].a,&r[3].a);
			r[1].id=1;r[2].id=2;r[3].id=3;
			sort(r+1,r+1+3);
			a[i].id=i;
			a[i].num[1]=r[1].a;
			a[i].num[2]=r[2].a;
			a[i].num[3]=r[3].a;
			a[i].inx[1]=r[1].id;
			a[i].inx[2]=r[2].id;
			a[i].inx[3]=r[3].id;
			a[i].d1=a[i].num[1]-a[i].num[2];
			a[i].d2=a[i].num[2]-a[i].num[3];
		}
		sort(a+1,a+1+n);
		int m[4]={0};
		for(int i=1;i<=n;i++){
			if(m[a[i].inx[1]]<n/2){
				m[a[i].inx[1]]++;
				ans+=a[i].num[1];
			}else if(m[a[i].inx[2]]<n/2){
				m[a[i].inx[2]]++;
				ans+=a[i].num[2];
			}else if(m[a[i].inx[3]]<n/2){
				m[a[i].inx[3]]++;
				ans+=a[i].num[3];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}