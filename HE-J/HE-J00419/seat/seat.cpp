#include<bits/stdc++.h>
using namespace std;
int a[105],noi;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
	int ans=n*m;
	for(int i=1;i<=ans;i++)
	{
		int di;
		cin>>di;
		a[i]=di;
	} 
	int sum=a[1];
	sort(a+1,a+ans+1,cmp);
	for(int i=1;i<=ans;i++)
	{
		if(a[i]==sum)
		{
			noi=i;
			break;
		}
	}
    if(noi==1)
    {
    	cout<<1<<" "<<1;
    	return 0;
    }
    if(noi==ans)
    {
    	if(m%2==0)
    	{
    		cout<<n<<" "<<1;
    		return 0;
		}
		else
		{
			cout<<n<<" "<<m;
			return 0;
		}
	}
    if(noi<=n)
    {
    	cout<<1<<" "<<noi;
    	return 0;
	}
	else if(noi>n)
	{
		if(noi%2==0) 
		{
			cout<<(noi/n)<<" "<<n;
			return 0;
		}
		if(noi%2==1&&noi==n+1)
		{
		    cout<<(noi/n)+1<<" "<<n; 
		    return 0;
		}
		if((noi%2==0&&(noi/2)%2==1)||(noi%2==1&&(noi/2)%2==1)||(noi%2==0&&noi%n==2))
		{
			cout<<(noi/n)+1<<" "<<(noi%n);
     	}
	}
	return 0;
}
