#include <bits/stdc++.h>
using namespace std;
int a[105];
int cmp(int a,int b)
{
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++)
	{
		cin >> a[i];
	}
	int ming=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(ming==a[i])
		{
			int l=(i-1)/n+1;
			if(l%2==1)
			{
				cout << l << " " << (i-1)%n+1;
			}
			else
			{
				cout << l << " " << n-(i-1)%n;
			}
			break;
		}
	}
	return 0;
} 
//#Shang4Shan3Ruo6Shui4
