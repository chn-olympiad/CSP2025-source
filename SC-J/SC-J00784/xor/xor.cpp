#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;

ll n,k,a[N],cnt;
bool A=1,B=1;
ll cnt1,cnt0;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		if(a[i]!=1) A=0;
		if(a[i]!=1 && a[i]!=0) B=0;
		if(a[i]==1) cnt1++;
		if(a[i]==0) cnt0++;
	}
	if(A)
	{
		cout << n/2 << endl;
		return 0;
	}
	else if(B)
	{
		if(k==1)
		{
			cout << cnt1 << endl;
			return 0;
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1 && a[i+1]==1)
				{
					i+=2;
					cnt0++;
				}
			}
			cout << cnt0 << endl;
			return 0;
		}
	}


    
	ll l=1,r=1,x=a[1];
	while(1)
	{
//		cout << l << " " << r << " " << x << endl;
		if(x==k)
		{
//			cout << "( " << l << " , " << r << " )" << endl;
			r++;
			l=r;
			x=a[l];
			cnt++;
		}
		else
		{
			r++;
			x^=a[r];
		}
		
		if(r==n)
		{
			if(x==k)
			{
				cnt++;
//				cout << "( " << l << " , " << r << " )" << endl;
			}
			break;
		}
	}
	cout << cnt << endl;
	return 0;
}