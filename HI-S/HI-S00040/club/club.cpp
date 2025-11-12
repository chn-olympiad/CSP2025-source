#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","r",stdout);
	
	int d;
	int t;
	int E[10];
	int a1[20005];
	int a2[20005];
	int a3[20005];
	int n[100001];
	//变量 
	
	cin>>t;
	a1[0]=0;
	a2[0]=0;
	a3[0]=0;
	for(int i=1;i<=t;i++)
	{
		cin>>n[i];
		for(int j=1;j<=n[i];j++)
		{
			cin>>a1[j]>>a2[j]>>a3[j];
		}
	}
	//输入
	 
	E[1]=0;
	for(int k=1;k<=t;k++)
	{
	    for(int p=1;p<=n[k];p++)
	    {
	    	d=max(a1[p],a2[p]);
	    	d=max(d,a3[p]);
		    E[k]=E[k]+d;
	    }
    }
	//计算 
	
	
	//输出 
	for(int i=1;i<=t;i++)
	{
		cout<<E[i]<<endl;
	}
	return 0; 
} 
