#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z;
}a[100010];
bool cmp(node a,node b){
	return a.y-a.x>b.y-a.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n,sum=0;
		scanf("%d",&n);
		for(int i=1; i<=n; i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1; i+i<=n; i++)
			swap(a[i].x,a[i].y);
		for(int i=1; i<=n; i++)
			sum+=a[i].x;
		printf("%d\n",sum);
	}
	return 0;
}
