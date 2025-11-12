#include<bits/stdc++.h>
using namespace std;
int a[11451419];
//vocies will tell me that i should carry on~； 
//The Weeknd我唯一的神 ； 
//好吧其实我也喜欢初音未来； 
//其实hardbass也很好听； 
//谁说后朋不好听的 崔没有死 ； 
//抢鸡蛋大赛，现在开始！！！ 
	int n,k;
int k1()
{
	int ans=0;
	int kDeHe=-1;
	for(int i=0;i<n;i++)
	{
		if(a[i]==1)
		{
			ans++;
		}
/*
		if(a[i]==0)
		{
			if(a[i+1]==1)
			{
				ans++;
//				cout<<i<<" "<<ans<<"\n";	调试代码
				i+=1;
			}
		}
		else
		{
			if(a[i+1]==1 && i+1<n)
			{
				a[i+1]=0;
//				cout<<i<<" "<<ans<<"\n";	调试代码
			} 
			else
			{
				ans++;
				i+=1;
//				cout<<i<<" "<<ans<<"\n";  调试代码 
			}
		}
*/
	}
	return ans;
}
//真是，绕了好大一圈啊。 
int k0()
{
	int ans=0;
//	int kDeHe=-1;
	for(int i=0;i<n;i++)
	{
		
		if(a[i]==0)
		{
			ans++;	
		}	
		else
		{
			if(a[i+1]==1)
			{
				ans++;
				i+=1;
			}
		}
	}
	
	return ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	

	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	//异或是这个么^我不到啊啊啊啊啊啊啊啊啊啊！；
	
//	int d=2,a=1;
//	int b=0,c=3;
//	cout<<(d^a)^b; 
	
	//破防了
	//还好我只是来混个上机经验的 
	
	//看看特殊性质去
	//woc特B和C好像能蒸
	if(n<=2 && k== 0)
	{
		cout<<n/2;
	}
	else
	{
		if(k==0)
		{
			int aans=k0();
			cout<<aans;
		}
		else
		{
			cout<<k1();
		}
	}
	
	//我去大屏幕还有进度条过半警告
	//为什么没有dp和搜索我白练了么 
	return 0;
}
