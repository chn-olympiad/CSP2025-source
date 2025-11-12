#include<bits/stdc++.h>
using namespace std;
//typedef long long ll;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	int a[100];
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	if(n<3)
	{
		printf("0");
	}
	if(n==3)
	{
		int MAX=0,zong=0;
		for(int i=1;i<=3;i++)
		{
			zong=zong+a[i];
			if(a[i]>MAX)
			{
				MAX=a[i];
			}
		}
	
		if(MAX*2<zong)
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

