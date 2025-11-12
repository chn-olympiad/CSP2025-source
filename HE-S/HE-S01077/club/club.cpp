#include<bits/stdc++.h>
using namespace std;
int t; 
int main()
{
	freopen("clud.in","r",stdin);
	freopen("clud.out","w",stdout);
	//正整数t
	cin>>t;
	//定义变量，计数器
	int sum=0; 
	//输入t组测试组
	for(int i=1;i<=t;i++)
	{
		int n;
		cin>>n;
		//二维数组
		int a[n][3];
		//最大限度
		//每个部门最多人数 
		int xd=t/2;
		//定义变量，表示部门所照人数
		int ac=0,bc=0,cc=0; 
		//输入第j个人的兴趣 
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=3;k++)
			{
				cin>>a[j][k];
				sum+=a[j][k];
			}
		}
		cout<<sum;
	}
	return 0;
	//保存解注释 
}
