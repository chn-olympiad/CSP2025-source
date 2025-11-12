#include<bits/stdc++.h>
using namespace std;
int a[105];
int b[105];
int n;//hang shu
int m;//lie shu
int h;
int l;
int ans;
int high;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int aa=a[1];
	for(int i=1;i<=n*m;i++)
	{
		for(int j=1;j<=n*m;j++)
		{
			if(a[j]>=ans)
			{
				ans=a[j];
				high=j;
			}
		}
		b[i]=ans;
		//cout<<ans<<" ";
		a[high]=0;
		ans=0;
		high=0;
	}
	//cout<<endl;
	for(int i=1;i<=n*m;i++)
	{
		if(b[i]==aa)
		{
			high=i;
	    }
	}
	//cout<<high<<" ";
	if(high<=n)
	{
		cout<<"1"<<" "<<high;
	}
	else
	{
		l=high/n;
		l+=1;
		h=high%n;
		if(l%2==0)
		{
			cout<<l<<" "<<n-h+1;
		}
		if(l%2==1)
		{
			cout<<l<<" "<<h;
		}
	}
	return 0;
}
