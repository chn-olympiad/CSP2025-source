#include<bits/stdc++.h>
using namespace std;

int T;
int n;
struct aa{
	int x,y,z;
};
aa a[100010];

int a1[100010];
int a2[100010];
int a3[100010];

int ans=0;

void n2(){
	int ans=-1;
	ans=max(ans,a[1].x+a[2].y);
	ans=max(ans,a[1].x+a[2].z);
	ans=max(ans,a[1].y+a[2].z);
	ans=max(ans,a[2].x+a[1].y);
	ans=max(ans,a[2].x+a[1].z);
	ans=max(ans,a[2].y+a[1].z);
	printf("%d\n",ans);
}

void AAA(){//n=10^5 所有成员对第2,3个部门都不感兴趣 
	sort(a1+1,a1+1+n);
	int num=n;
	while(num>n/2){
		ans+=a1[num];
		num--;
	}
	printf("%d\n",ans);
}

int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--)
	{
		ans=0;
		
		scanf("%d",&n);
		
		bool A=1;
		
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			a1[i]=a[i].x;
			a2[i]=a[i].y;
			a3[i]=a[i].z;
			if(!(a[i].y==a[i].z&&a[i].z==0)) A=0;
		}
		
		if(A){
			AAA();
			continue; 
		}
		
		if(n==2){
			n2();
			continue;
		}
		
	}
	return 0;
}

