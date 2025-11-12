#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t,n,club=0,num=0,max1=-1,p=0;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		int club1[4]={0,n/2,n/2,n/2};
		int a[n+500][9];
		for(int p2=1;p2<=n;++p2)
		{
			club=-1;
		for(int j=1;j<=3;++j)
		{
			club++;
			cin>>a[p2][j];
			if(club=3) club=-1;
		}
		}
		club=0;
		for(int t1=1;t1<=n;++t1)//ren
		{
			max1=-1;
			for(int j=1;j<=3;j++)
			{
				if(max1<a[t1][j]&&club1[j]>=0)
				{
					max1=a[t1][j];
					p=j;
				}
			}
			club1[p]--;
			num+=max1;
		}
		cout<<num<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
for(int i=0;i<3;i++)
		{
			cout<<club1[i]<<endl;
		}
							cout<<p+1<<" "<<'p'<<endl;
												cout<<max1<<endl;
												
												
								/0				
*///
