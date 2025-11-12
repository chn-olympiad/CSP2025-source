#include<iostream>
using namespace std;
long long n,k;
long long a[500005];
bool check(int c)
{
	
	int s=0,i=0,j=0,su;
	while(i<=n-1)
	{
		su=a[i];
		j=i;
		while(j<=n-1)
		{
			//cout<<i<<' '<<j<<' '<<sum(i,j)<<endl;
			//su=sum(i,j);
			if(su==k)
			{
				s++;
				i=j;
				break;
			}
			
			j++;
			su=su^a[j];
		}
		
		
		i++;
		
	}
	if(s>=c)return 1;
	else return 0;

}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<=n-1;i++)cin>>a[i];
	int l=0,r=n,mid=(l+r)/2;
	while(l+1<r)
	{
		mid=(l+r)/2;
		//cout<<mid<<' '<<check(mid)<<endl;
		
		if(check(mid))
		{
			l=mid;
		}
		else
		{
			r=mid;
		}
		
	}

	cout<<l;
	return 0;
}
