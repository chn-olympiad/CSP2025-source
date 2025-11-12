#include<bits/stdc++.h>
using namespace std;
int a[1002];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,pm=0,ta=0,sd=0;
	int r=0,c=0;
	scanf("%d%d",&n,&m);
	sd=n*m;
	for(int i=1;i<=sd;i++)
		scanf("%d",&a[i]);
	ta=a[1];
	sort(a+1,a+sd+1,greater<int>());
	for(int i=1;i<=sd;i++)
	{
		pm++;
		if(a[i]==ta)
			break;
	}
	r=(pm+n-1)/n;
	if(r%2!=0)
	{
		if(pm%n==0)
			c=n;
		else
			c=max(pm%n,1);
	}	
	else
	{
		if(pm%n==0)
			c=1;
		else
			c=(n-pm%n)+1;
	}
	printf("%d %d",r,c);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
