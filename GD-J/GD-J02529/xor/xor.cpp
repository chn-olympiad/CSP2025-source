#include<bits/stdc++.h>
using namespace std;

int n,k;
int t=0,f=0;//统计1,0的个数，其中t统计1(true)，f统计0(false) 

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i <= n; i++)
	{
		int num;
		cin>>num;
		if(num == 1)
		{
			t++;	
		} 
		else if(num == 0)
		{
			f++;
		}
	}
	if(f == 0)//满足特殊性质A 
	{
		cout<<n/2;
		return 0;
	}
	if(k == 0)
	{
		cout<<n/2;
        return 0;
	}
	if(k == 1)
	{
		if(t == f)
		{
			cout<<n/2;
			return 0;
		}
	}
	return 0;
}
