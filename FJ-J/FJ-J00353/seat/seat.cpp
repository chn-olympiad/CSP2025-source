#include<bits/stdc++.h>
using namespace std;
//当列为奇数时，行为1~N
//当列为偶数时，行为N~1
//(x,y)->(行,列) 
//x=num-(y-1)*n
int n,m;
int s_list[120];
int sum=0;
int a_1 = -1;
int min_ci =-1;
int c,r;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	sum=n*m;
	for(int i=0;i<sum;i++)
	{
		cin>>s_list[i];
	}
	a_1 = s_list[0];
	sort(s_list,s_list+sum);
	int j=1;
	for(int i=sum-1;i>=0;i--)
	{
//		cout<<j<<" "<<s_list[i]<<endl;
		if(s_list[i]==a_1)
		{
			min_ci = j;
			break;
		}
		j++;
	}
	//根据min_ci计算座位 
	c=min_ci/n;
	if(min_ci%n>0)
	{
		c++;
	}
	if(c%2==0)
	{//n~1
		r=n-(min_ci%n)+1;
	}
	else
	{
		r=min_ci%n;
	}
//	c--;
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
