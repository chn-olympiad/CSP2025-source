#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,k;
struct nood{
	int x,i;
};
nood a[105];
bool cmp(nood a,nood b){
	return a.x>b.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);k=n*m;
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&a[i].x);a[i].i=i; 
	}
	sort(a+1,a+1+k,cmp);k=0;
	for(int i=1;i<=m;i++)
	{
		if(i%2==1){
			for(int j=1;j<=n;j++)
			{
				k++;
				if(a[k].i==1){
					x=j,y=i;break;
				}
			}
			if(x&&y)break;
		}
		else {
			for(int j=n;j>=1;j--)
			{
				k++;
				if(a[k].i==1){
					x=j,y=i;break;
				}
			}
			if(x&&y)break;
		}
	}
	printf("%d %d",y,x);
	return 0;
}
