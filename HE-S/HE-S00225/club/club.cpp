#include<bits/stdc++.h>
using namespace std;
long long a[10000];
long long b[10000];
long long c[10000];
long long KO[10000][5];
int main()
{
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//输入几组数据 
	//int t;
	//cin>>t;
	//输入几个人 
	int n;
	cin>>n;
	//输入满意值 
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		cin>>b[i];
		cin>>c[i];
	}
	///定义一个二维数组
	//将他们的喜爱程度导入KO
	for(int j=0;j<n;j++)
	{
	   	KO[j][0]=a[j];
	   	KO[j][1]=b[j];
	   	KO[j][2]=c[j];
	}
    //所有组合找最大
    int max=0;
    int max2=0;
		//判断最大
	    //测试 
	    //for(int i=0;i<n;i++)
	    //{
	    //	for(int j=0;j<3;j++)
	    ///    {
	    //	    cout<<KO[i][j]<<" ";    
	    //   }
	    //    cout<<endl;
	    //}
	    //测试成功
		//KO==喜爱程度的二维数组
	int biaoji1=0;
	int biaoji2=0;
	for(int j=0;j<3;j++)
	{ 
		for(int k=0;k<n;k++)
		{   
		    if(max<KO[j][k])
		    {
		    	max=KO[j][k];
		    	biaoji1=j;
		    	biaoji2=k;
				 
			}
		    
	    }
	    
    }
    KO[biaoji1][biaoji2]=0;
    for(int j=0;j<3;j++)
	{ 
		for(int k=0;k<n;k++)
		{   
		    if(max2<KO[j][k])
		    {
		    	max2=KO[j][k]; 
			}
		    
	    }
	    
    }
	max+=max2;   
	cout<<max;

	return 0;
}
