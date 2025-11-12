#include <bits/stdc++.h>
using namespace std;
long long num=0;
const int N=998,E=244,I=353;
int n,a[5001];
int maxl=0;
void count_num(int x,int j,int maxl,int sum)
{
	if (x==0){
		if (sum>maxl*2) num+=1;
		return ;
	}
	for (int i=j+1;i<=n;i++)
	{
		count_num(--x,i,max(maxl,a[i]),sum+a[i]);
	}
	return ;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	cin>>n;
    for (int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	for (int i=3;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			count_num(i-1,j,a[j],a[j]);
		}
	}
	num%=N;
	num%=E;
	num%=I;
	cout<<num;
	return 0;
}

