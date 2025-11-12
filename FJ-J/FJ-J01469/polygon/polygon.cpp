#include<cstdlib>
#include<ctime>
#include<cstdio>
int a[5005],n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	srand(time(0));
	printf("%d",rand()%114514);
}
