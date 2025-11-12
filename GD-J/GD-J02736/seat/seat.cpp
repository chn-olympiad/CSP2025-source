#include<bits/stdc++.h>
using namespace std;
int n,m;
struct sd{
	int grade,i;
}a[1005];
int sum;
bool cmp(sd x,sd y)
{
	return x.grade>y.grade;
}
//排序+查找位置+数学计算 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i].grade);
		a[i].i=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].i==1) sum=i;
	}
	
	//列
	int t=sum/n,h=sum%n;
	if(sum%n!=0) t++;
	printf("%d ",t);
	
	//行 
	if(h==0) h=n; 
	if(t%2==1) printf("%d",h);
	else printf("%d",n-h+1);
	return 0;
}
