#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=15;
int s[N*N];
int rank;
int cnt;
int num2;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&s[i]);
		if(i==1) cnt=s[i];
	}
	sort(s+1,s+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(s[i]==cnt)
		{
			rank=i;
			break;
		}
	}
	int num1=rank%n; 
	if(num1!=0)
	{
		num2=rank/n+1; 
	}
	else num2=rank/n;
	if(num2%2==0)
	{
		if(num1==0) cout<<num2<<' '<<1; 
		else cout<<num2<<' '<<n-num1+1;
	}
	else
	{
		if(num1==0) cout<<num2<<' '<<n;
		else cout<<num2<<' '<<num1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

