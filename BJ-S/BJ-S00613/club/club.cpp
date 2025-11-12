#include <bits/stdc++.h>
#include <ctime>
using namespace std;



int a[81],g[11];
int main()
{
	srand(time(0));
	for(int i=1;i<=80;i++)a[i]=i;
	while(1)
	{
		cout<<"选择个数\n";
		for(int i=1;i<=10;i++)g[i]=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>g[i];
		}
		for(int i=1;i<=8000;i++)
		{
			int r1=rand()%80+1;
			int r2=rand()%80+1;
			swap(a[r1],a[r2]);
		}
		int cnt=0;
		for(int i=1;i<=20;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[i]==g[j])cnt++;
			}
		}
		cout<<"中奖号码：";
		for(int i=1;i<=20;i++)cout<<a[i]<<" ";
		cout<<endl;
		cout<<"中将个数："<<cnt<<endl;
	}
	return 0;
}
