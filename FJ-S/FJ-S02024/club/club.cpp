#include<bits/stdc++.h>
using namespace std;
int a[10005][10005];
int main()
//求分配方案中满意度最大值 
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,flag,max;//t组，每组n个新成员
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		flag=0,max=0;		
		cin>>n;
		for(int j=1;j<=n;j++)
		{	
			for(int k=1;k<=3;k++)
			{
				cin>>a[i][j];//新成员对第k个部门的满意度
				if(a[i][j]>=max) max=a[i][j];
			}
			flag+=max;
		}
		cout<<flag<<endl;
		flag=0,max=0;
	}
}
