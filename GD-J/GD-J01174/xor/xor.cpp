#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n,k;
int a[50005]={};
int aps[50005]={};
int temp,ans=-1;

int numb(int i)
{
	if (i>n) return 0;
	if(aps[i]!=0)
	{
		return max(numb(aps[i])+1,numb(i+1));
		
	}
	else return numb(i+1);
	
}

int main()
{
	//现场探索的结果：|是位或，&是位与, ^是异或  yee~ but区间是什么,omg,怎么办，完了完了 ,woooooooo
	//写完了写完了对了对了我噢噢噢噢哦哦wooooooooo ，全错了 啊啊啊 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<n;i++)
	{
		temp=a[i];
		for(int j=i+1;j<=n;j++)
		{
			for(int k=i+1;k<=j;k++)
			{
				temp=temp^a[k];
			}
			if(temp==k)
			{
				if(aps[i]!=0) aps[i]=min(aps[i],j);
				else aps[i]=j;
			}
		}
	}

	cout << numb(1);
	return 0;
}
