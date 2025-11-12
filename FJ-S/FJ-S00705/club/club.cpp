#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
long long num;
int a[100006][4];
bool zwei[100006];
int hana[4];
void zzz(int k,int akka)
{
	if(k==n+1)
	{
		if(akka>=num)
		{
			num=akka;
		}
		return;
	}
	else
	{
		for(int i=1;i<=3;i++)
		{
			if(zwei[k]==0&&hana[i]<n/2)
			{
				zwei[k]=1;
				akka+=a[k][i];
				hana[i]++;
				zzz(k+1,akka);
				zwei[k]=0;
				hana[i]--;
				akka-=a[k][i];
			}
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int tttt;
	cin>>tttt;
	while(tttt--)
	{
		num=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		zzz(1,0);
		cout<<num<<endl;
	}
}
