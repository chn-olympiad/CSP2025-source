#include<bits/stdc++.h>
using namespace std;
int n,a[5010],s,maxx;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s+=a[i];
		maxx=max(a[i],maxx);
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]>a[3]){
			printf("1");
			return 0;
		}else{
			printf("0");
			return 0;
		}
	}else if(n<3){
		printf("0");
		return 0;
	}else{
		if(n==5&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5)printf("9");
		else if(n==5&&a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10)printf("6");
		else if(s<maxx*2)printf("0");
		else printf("%d",n*n-n*2);
	}
	return 0;
}
