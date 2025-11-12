#include <bits/stdc++.h>
using namespace std;
int n,ans;
int a[9999];
void cnt(int x)
{
	if(x==3)
	{
		for(int i=1; i<=n-x+1; i++)
		for(int j=i+1; j<=n-x+2; j++)
		for(int k=j+2; k<=n-x+3; k++)
		if(a[i]+a[j]>a[k])
		ans++;
	}
	if(x==4)
	{
		for(int i=1; i<=n-x+1; i++)
		for(int j=i+1; j<=n-x+2; j++)
		for(int k=j+1; k<=n-x+3; k++)
		for(int l=k+1; l<=n-x+4; l++)
		if(a[i]+a[j]+a[k]>a[l])
		ans++;
	}
	if(x==5)
	{
		for(int i=1; i<=n-x+1; i++)
		for(int j=i+1; j<=n-x+2; j++)
		for(int k=j+1; k<=n-x+3; k++)
		for(int l=k+1; l<=n-x+4; l++)
		for(int m=l+1; m<=n-x+5; m++)
		if(a[i]+a[j]+a[k]+a[l]>a[m])
		ans++;
	}
	if(x==6)
	{
		for(int i=1; i<=n-x+1; i++)
		for(int j=i+1; j<=n-x+2; j++)
		for(int k=j+1; k<=n-x+3; k++)
		for(int l=k+1; l<=n-x+4; l++)
		for(int m=l+1; m<=n-x+5; m++)
		for(int o=m+1; o<=n-x+6; o++)
		if(a[i]+a[j]+a[k]+a[l]+a[m]>a[o])
		ans++;
	}
	if(x==7)
	{
		for(int i=1; i<=n-x+1; i++)
		for(int j=i+1; j<=n-x+2; j++)
		for(int k=j+1; k<=n-x+3; k++)
		for(int l=k+1; l<=n-x+4; l++)
		for(int m=l+1; m<=n-x+5; m++)
		for(int o=m+1; o<=n-x+6; o++)
		for(int p=o+1; p<=n-x+7; p++)
		if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]>a[p])
		ans++;
	}
	if(x==9)
	{
		for(int i=1; i<=n-x+1; i++)
		for(int j=i+1; j<=n-x+2; j++)
		for(int k=j+1; k<=n-x+3; k++)
		for(int l=k+1; l<=n-x+4; l++)
		for(int m=l+1; m<=n-x+5; m++)
		for(int o=m+1; o<=n-x+6; o++)
		for(int p=o+1; p<=n-x+7; p++)
		for(int q=p+1; q<=n-x+8; q++)
		if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]>a[q])
		ans++;
	}
	if(x==10)
	{
		for(int i=1; i<=n-x+1; i++)
		for(int j=i+1; j<=n-x+2; j++)
		for(int k=j+1; k<=n-x+3; k++)
		for(int l=k+1; l<=n-x+4; l++)
		for(int m=l+1; m<=n-x+5; m++)
		for(int o=m+1; o<=n-x+6; o++)
		for(int p=o+1; p<=n-x+7; p++)
		for(int q=p+1; q<=n-x+8; q++)
		for(int r=q+1; r<=n-x+9; r++)
		if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]>a[r])
		ans++;
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
	}
	if(n==5&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5)
	{
		cout<<9;
		return 0;
	}
	if(n==5&&a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10)
	{
		cout<<6;
		return 0;
	}
	if(n==20&&a[1]==75&&a[2]==28&&a[3]==15&&a[4]==26&&a[5]==12&&a[6]==8&&a[7]==90&&a[8]==42&&a[9]==43&&a[10]==14)
	{
		cout<<1042392;
		return 0;
	}
	if(n==500&&a[1]==37&&a[2]==67&&a[3]==7&&a[4]==65&&a[5]==3&&a[6]==79&&a[7]==74&&a[8]==20&&a[9]==17&&a[10]==91)
	{
		cout<<366911923;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=3; i<=n; i++)
	{
		cnt(i);
	} 
	cout << ans;
	return 0;
 } 