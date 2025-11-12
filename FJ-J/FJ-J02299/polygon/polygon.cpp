#include <bits/stdc++.h>
using namespace std;


//双指针+前缀和
/* 
int n;
int a[5000];
int b[5000];

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=0;i<n;i++)cin >> a[i];
	b[0]=a[0];
	for(int i=1;i<n;i++)
	{
		b[i]=b[i-1]+a[i];
	}
	
	 
	return 0;
}
*/

//dfs   15-20针对得分 
 
int n;
int a[5000];
long long ans;
bool sp=true; 

int dfs(int t,int l,int num,int m)
{
	num+=a[t];
	l++;
	if(a[t]>m)m=a[t];
	if(l>=3 && num>2*m)
	{
		ans++;
		ans%=998244353;
		//cout << l << " " << num << " " << m << endl;
	}
	if(t==n-1)return 0;
	for(int i=t+1;i<n;i++)
	{
		dfs(i,l,num,m);
	}
	return 0;
}


long long c(int m,int n)
{
	long long o=1;
	int j=1;
	for(int i=m-n+1;i<=m;i++)
	{
		o*=i;
		while(o>998244353 && j<=n)
		{
			o/=j;
			j++;
		}
		o%=998244353;
	}
	for(;j<=n;j++)o/=j;
	return o;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		if(a[i]!=1)sp=false;
	}
	if(sp && n>20)
	{
		for(int i=3;i<=n;i++)
		{
			ans+=c(n,i);
			ans%=998244353;
		}
	}
	else
	{
		for(int i=0;i<n-2;i++)dfs(i,0,0,0);
	}
	cout << (ans%998244353);
	 
	return 0;
}
