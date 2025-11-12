#include<bits/stdc++.h>
using namespace std;
int a[1021021];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%d",&n);
	int big=0;
	int s=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s+=a[i];
		if(a[i]>big)
		{
			big=a[i];
		} 
	}
	if(n<3)
	{
		printf("0");
		return 0;
	}
	else
	{
		if(s>2*big)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
	}
	return 0;
}

