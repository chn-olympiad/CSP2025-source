#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[10000111],sum,cnt,ans,xzy,js1;
double js,m1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	if(n!=1)
	{
	m1=m;
	sum=n*m;
	for(int i=1;i<=sum;i++)
	cin>>a[i]; 
	cnt=a[1];
	sort(a+1,a+1+sum);
	for(int i=1;i<=sum;i++)
	{
		if(a[i]==cnt)
		{
			js=i;
			break;	
		}	
	}
	js=sum-js+1;
	ans=ceil(js/m1);//判断第几列！纵坐标 
	js1=js;
	xzy=js1%m;//
	if(ans%2!=0&&xzy==0)//奇数列 并且 在最后一个 
	{
		cout<<ans<<" "<<m;
	 } 
	if(ans%2!=0&&xzy!=0)
	{
		cout<<ans<<" "<<xzy;
	}
	if(ans%2==0&&xzy==1)//偶数列 
	{
		cout<<ans<<" "<<m;
	}
	if(ans%2==0&&xzy==0)
	{
		cout<<ans<<" "<<'1';
	}
	if(ans%2==0&&xzy!=0&&xzy!=1)
	{
		cout<<ans<<" "<<m-xzy+1;
	}
	}
	else
	{
		m1=m;
		sum=n*m;
		for(int i=1;i<=sum;i++)
		cin>>a[i];
		cnt=a[1];
		sort(a+1,a+1+sum);
		for(int i=1;i<=sum;i++)
		{
			if(a[i]==cnt)
			{
				js=i;
				break;
			}
		}
		cout<<n<<" "<<sum-js+1;
	}
	fclose(stdin);
	fclose(stdout);
}
//保底得分，检查！！！ 
