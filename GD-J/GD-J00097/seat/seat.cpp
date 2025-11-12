#include <bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,ansn=1,ansm=1;
	cin>>n>>m;
	long long tadechengji;
	long long chengji[n*m]={0};
	cin>>tadechengji;
	chengji[0]=tadechengji;
	for(int i=1;i<n*m;i++)
	{
		cin>>chengji[i];
	}
	sort(chengji,chengji+n*m,cmp);
	int dangqianfangxiang=0;
	for(int i=0;i<n*m;i++)
	{
	if(dangqianfangxiang==0)
	{
		if(chengji[i]==tadechengji)
		{

				cout<<ansn<<" "<<ansm;
				return 0;
			
		}
		if(ansm!=m) 
		{
			ansm++;
		}
		else
		{
			ansn++;
			dangqianfangxiang=1;
		}
	}
	else
	{
		if(ansm!=1) 
		{
			ansm--;
		}
		else
		{
			ansn++;
			dangqianfangxiang=0;
		}
	}
		
	}
	return 0;
}
