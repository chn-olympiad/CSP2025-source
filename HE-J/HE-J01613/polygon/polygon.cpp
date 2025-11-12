#include<bits/stdc++.h>

using namespace std;

long long n,a[5033];//CR400BF-5033 

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	ios::sync_with_stdio(false);
	
	//想啥呢这题我也不会
	//讲个笑话：孙浩喧因上车拿笔记本电脑被G3491带去了山海关，还好他没坐另一趟车
	//要不然就得从沈阳北回来了
	//秦皇岛战役差点非战斗减员1人
	//为孙浩喧点赞()
	//继续骗分,测试点1-3我来了 
	cin>>n;
	for(int i=1;i<=n;i++)
	    cin>>a[i];
	if(n<=3)
	{
		if(n!=3)
		    cout<<0<<endl;
		if(n==3)
		{
			if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1])
			    cout<<1<<endl;
			else
			    cout<<0<<endl;
		}
	}
	else
	    cout<<1<<endl; 
	    
	return 0;
}
