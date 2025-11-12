#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>n>>m;
	int temp=n*m;
	long long a[temp];
	for (int i=0;i<temp;i++)//输入 
	{
		cin>>a[i];
	}
	int xu[100]={0};//按大小排序 
	int xr=a[0];//小R的成绩 
	for (int i=0;i<temp;i++)
	{
		for(int j=temp;j>=0;j--)
		{
			if(a[i]>xu[j])//将最后的xu和第一个成绩比较 
			{
				xu[j+1]=xu[j];//如果比xu大的话，将这一位的xu放到下一位 
				xu[j]=a[i];//这一位用a[i] 
			}
			else
			{
				xu[j+1]=a[i];//如果比他小则放到下一位
				break; 
			}
		}
	}
	int count=0;
	for (int i=0;i<=temp;i++)//从xu中寻找小R 
	{
		count++;
		if(xu[i]==xr)
		{
			break;
		}
	}
	int c,r;//列和行 
	if(count>n)
	{
		r=count%n;//行 
		c=count/n+1;//列 
		if(c%2==0)//双数列，从后往前 
		{
			r=n-r+1;
		}
	}
	else//小R在第一列 
	{
		c=1;
		r=count;
	 } 
	cout << c <<" "<< r;
	
	return 0;
}
