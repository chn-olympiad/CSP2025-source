#include <bits/stdc++.h>
using namespace std; 
const int mod=998244353;
int n,a[501],ans,c[501],m;
string ch;
int main()
{
	freopen("empoly.in","r",stdin);
	freopen("empoly.out","w",stdout);
	scanf("%d %d",&n,&m);
	cin>>ch;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		c[a[i]]++;
	}
    do
    {
    	int sum=0,cnt=0;
    	for(int i=1;i<=n;i++)
    	{
    		if(ch[i-1]=='0') 
    		{
    			sum++;
    			continue;
			}
			if(sum>=a[i])
			{
				sum++;
				continue;
			}
			cnt++;
		}
		int pq=1;	
		for(int i=0;i<=n;i++)
			for(int j=c[i];j>=1;j--)
				pq=(long long)pq*(long long)j%mod;		
	    if(cnt>=m) ans=(ans+pq)%mod;
	}while(next_permutation(&a[1],&a[n]+1));
	printf("%d",ans);
	return 0;

}
