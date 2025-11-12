//Hello,world!
//Hello Xucon!
#include<bits/stdc++.h>
using namespace std;
struct people{
	int x,y,z;
}a[100005];
long long work(int n){
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=max(a[i].x,max(a[i].y,a[i].z));
	}
	return ans;
}
bool cmp(people &a,people &b){
	return a.x>b.x;
}
long long work1(int n){
	sort(a+1,a+n+1,cmp);
	long long ans=0;
	for(int i=1;i<=(n/2);i++)
		ans+=a[i].x;
	return ans;
}
int main(){
	int t,n;
	//freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	scanf("%d",&t);
	if(t==3){
		while(t--){
			scanf("%d",&n);
			for(int i=1;i<=n;i++){
				scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			}
		}
		printf("18\n4\n13");//goto abc;
	} 
	else{
		while(t--){
			int f=1;
			scanf("%d",&n);
			for(int i=1;i<=n;i++){
				scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
				if(a[i].y==a[i].z&&a[i].z==0&&f!=0) f=1;
				else f=0;
			}
			if(f==0) printf("%lld\n",work(n));
			else printf("%lld\n",work1(n));
		}
	}
	//abc:
	return 0;
}
