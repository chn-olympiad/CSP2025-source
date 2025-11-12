#include<bits/stdc++.h>
using namespace std;

long long n;
long long a[100005];
long long ans = 0;

void dg(long long l,long long r,long long all,long long maxn,long long num) 
{
	if(r==l)
	{
		if(all >maxn) 
		{
			ans++;
			//cout << "  all=" << all  << "  > " << maxn  << "  you  " << num << "  ge" << endl;;
		}
			
		if(all + a[l] > maxn)
		{
			ans++;
			//cout << "  all=" << all + a[l] << "  > " << maxn << "  you  " << num+1 << "  ge  " << endl;;
		}
		return;
	}
	
	
	
		//cout << "xz:a" <<  l  << " = "<<  a[l] << "   di" << num+1 << " ge"  << endl;;
		dg(l+1,r,all+a[l],maxn,num++);
		//cout << "bx:a" <<  l  << " = "<<  a[l] << "   di" << num << " ge"  << endl;;
		dg(l+1,r,all,maxn,num);
	
	return;
}



int main()
{	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(long long i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	/*
	for(long long i = 1;i <= n;i++)
	{
		cout << a[i];
	}
	cout << endl;
	* */
	for(long long i = n;i >=3;i--)
	{
		//cout << "maxn ==  " << a[i] << endl;
		dg(1,i-1,0,a[i],0);
		ans %= 998244353;
	}
	
	
	
	/*
	long long e;
	for(long long i = 3;i <= n;i++)
	{
		for(long long j = n;j >=i;j--)
		{
			
			long long maxn = a[j];
			for(long long q = j-1;q >=i-1;q--)
			{
				e = q-1;
				long long d = maxn-a[q];
				for(long long y = q-1;y >=1;y--)
				{
					if(a[y] <= d)
					{
						e = q-y-1;
						
						break;
					}
				}
				ans += e;
				cout << i << "ge  " << j << "/" << q << "  " << e << "zhong" << endl; 
			}
			
		}
	} 	
	*/
	cout << ans << endl;
	return 0;
}
