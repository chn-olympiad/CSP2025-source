#include<bits/stdc++.h>
using namespace std;

int Rs[114];//我是日石Rs终极大魔头 
/*
void bubblePaiXu()
{
	for(int i=0;)
	return ;
}
*/

//吐槽为啥DEV的debug不能用 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	
	int rs=n*m;
	cin>>Rs[0];
	int ans=1;
	for(int i=1;i<rs;i++)
	{
		cin>>Rs[i]; 
		if(Rs[i]>Rs[0])
		{
			ans++;
		}
	}//其实完全没必要存但是懒得改了 
	
	if(ans%n==0)
	{
		if((ans/n)%2==0)
		{
			cout<<ans/n<<" "<<1;
		}
		else
		{
			cout<<ans/n<<" "<<n;
		}
	}
	else
	{
		cout<<ans/n+1<<" ";
		if((ans/n)%2>0)
		{
			cout<<n-ans%n+1; 
		}
		else
		{
			cout<<ans%n;
		}
	}
	
//	cout<<"\n"<<ans;//调试用debug代码 
	return 0;
}



