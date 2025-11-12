#include<bits/stdc++.h>
#define int long long
#define N 500005
using namespace std;

int n,k;
array<int,N> a;

int ans,num;

signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    scanf("%lld",&a.at(i) );
    
    for(int i=1;i<=n;i++)
    {
    	num=a.at(i);
    	if(num==k)
    	{
    		ans++;
    		continue;
		}
		
    	for(int j=i+1;j<=n;j++)
    	{
    		num^=a.at(j);
    		if(num==k)
    		{
	    		ans++;
	    		i=j;
	    		break;
			}
		}
	}
	
	cout<<ans<<endl;
    return 0;
}
