#include <bits/stdc++.h>
using namespace std;

int m,n,c,r; 
int s[101]={};

//向上取整函数
int upint(int set,int n)//set:小R排名（下标+1） n:行数 
{
	if(set%n==0)	return set/n;
	else	return set/n+1;
}
//计算r的函数
int sum_r(int c,int set,int n)//c:小R在第c列  set:小R排名  n:行数 
{
	//判断c奇偶性，奇数为1，偶数为0
	int if_ji=c%2;
	int dir;//每两列中的第几个 
	int n_2=2*n; 
	if(set%n_2==0)	dir=n_2;
	else	dir=set%n_2;
	if(if_ji==0)//偶数
	{
		return 2*n+1-dir;
	}
	else if(if_ji==1)//奇数 
	{
		return dir; 
	} 
}

int main()
{
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	
	//输入 n,m
	cin >> n >> m;
	//c1:s的临时下标 
	int c1=0;
	int temp_input=0;
	for(int i=0;i<=n*m-1;i++)
	{
		cin >> temp_input;
		s[c1]=temp_input;
		c1++;
	}
	
	int const a1=s[0];//小R的成绩分数 
	
	//冒泡排序
	int temp=0;
	while(temp<c1)
	{
		for(int i=0;i<=c1-1;i++)
		{
			if(s[i]<s[i+1])
			{
				int tmp=s[i];
				s[i]=s[i+1];
				s[i+1]=tmp;
			}
		}
		temp++;
	}
	
	//寻找小R成绩是第(几-1)名
	int c2=0;//小R在s数组中的下标 
	while(s[c2]!=a1)
	{
		c2++;
	}
	c=upint(c2+1,n);
	r=sum_r(c,c2+1,n);
	cout << c << ' ' << r;
	
	
	fclose(stdin);
	fclose(stdout); 
	
	return 0;
}