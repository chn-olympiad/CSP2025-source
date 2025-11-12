#include<bits/stdc++.h>
using namespace std;
struct stu{
	int x,y,z;
	int mx1,mx2,mx3;
	int pl1,pl2,pl3;
}a[100010];
int cl1[100010],cl2[100010],cl3[100010];
int sum1,sum2,sum3;
int tot2=0,tot3=0;
bool cmp(stu m,stu n){
	return m.x>n.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;scanf("%d",&t);
	while(t--){
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			a[i].mx1=a[i].x;a[i].mx2=a[i].y;a[i].mx3=a[i].z;
			a[i].pl1=1;a[i].pl2=2;a[i].pl3=3;
			if(a[i].mx1<a[i].mx2){
				swap(a[i].mx1,a[i].mx2);
				swap(a[i].pl1,a[i].pl2);
			}
			if(a[i].mx2<a[i].mx3){
				swap(a[i].mx2,a[i].mx3);
				swap(a[i].pl3,a[i].pl2);
			}
			if(a[i].mx1<a[i].mx2){
				swap(a[i].mx1,a[i].mx2);
				swap(a[i].pl1,a[i].pl2);
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i].pl1==1){
				sum1++;
				cl1[sum1]=a[i].mx1-a[i].mx2;
				ans+=a[i].mx1;
				//printf("%d %d %d\n",1,cl1[sum1]);
			}
			else if(a[i].pl1==2){
				sum2++;
				cl2[sum2]=a[i].mx1-a[i].mx2;
				ans+=a[i].mx1;
				//printf("%d %d %d\n",2,cl2[sum2]);
			}
			else if(a[i].pl1==3){
				sum3++;
				cl3[sum3]=a[i].mx1-a[i].mx2;
				ans+=a[i].mx1;
				//printf("%d %d %d\n",3,cl3[sum3]);
			}
		}
		sort(cl1+1,cl1+1+sum1);
		sort(cl2+1,cl2+1+sum2);
		sort(cl3+1,cl3+1+sum3);
		if(sum1>n/2){
			for(int i=1;i<=sum1-(n/2);i++) ans-=cl1[i];
		}
		if(sum2>n/2){
			for(int i=1;i<=sum2-(n/2);i++) ans-=cl2[i];
		}
		if(sum3>n/2){
			for(int i=1;i<=sum3-(n/2);i++) ans-=cl3[i];
		}
		printf("%d\n",ans);
		sum1=sum2=sum3=0;
	}
	return 0;
} 
