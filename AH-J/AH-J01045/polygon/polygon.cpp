#include <bits/stdc++.h>
using namespace std;
int a[5005],cnt,n;
long long choices( )
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		int l=i+1,r=l+1,lastl=l,lastr=r;
		while(l<=r)
		{
			int sum=a[i],maxa=a[i];  
			for(int j=l;j<=r;j++)
			{
				sum+=a[j];
				maxa=max(maxa,a[j]);
				   
			}
			if(sum>2*maxa)
			{
				cnt++;   
			}
			if(r+1<=n)
			{
				r++;
				lastr=r;
			}else if(l+1>=n){
				break;
			}else{
				l++;
				lastl=l;
				r=l+1;
				lastr=r;
			}
			if(lastl==i+1 && lastr-lastl+1<=n-2 &&lastr<n)
			{
				for(int i=lastr;i<=n;i++)
				{
					
						sum+=a[i];
						maxa=max(maxa,a[i]);
					
					maxa=max(maxa,a[i]);
					if(sum>2*maxa)
					{
						cnt++;
					}
					sum-=a[i];
				}
			}
		}
	}
	return cnt%998244353;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
		cin>>a[i];
	}
	cout<<choices();
}
