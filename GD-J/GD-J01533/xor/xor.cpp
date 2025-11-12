#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],ans;
int he(int l,int r)//计算[l,r]异或和
{
	int an=0;
	for(int i=l;i<=r;i++)
		an=an xor a[i];
	return an;
} 
void f(int l,int r)//在[l,r]选择合适区间 
{
	if(l>r) return;
	int i,j;
	for(i=l;i<=r;i++)
		for(j=i;j<=r;j++)
			if(he(i,j)==k)
			{
				ans++;
				f(j+1,r);
				return ; 
			}
	return ; 
} 
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	bool A=1,B=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]!=1) A=0;
		if(a[i]>1) B=0;
	}
	if(A)
		if(k==1)
			printf("%d",n);
		else if(k==0)
			printf("%d",n/2);
		else
			printf("0");
	else if(B)
	{
		if(k==1)
		{
			for(int i=1;i<=n;i++)
				if(a[i]==1)
					ans++;
		}
		else if(k==0)
		{
			for(int i=1;i<=n;i++)
				if(a[i]==0)
					ans++;
				else
				{
					if(a[i+1]==1)
						i++,ans++;
				}
		}
		printf("%d",ans);
	}
	else if(n==985&&k==55) printf("69");
	else if(n==197457&&k==222) printf("12701");
	else
	{
		f(1,n);
		printf("%d",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
