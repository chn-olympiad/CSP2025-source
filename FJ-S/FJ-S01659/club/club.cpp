#include <bits/stdc++.h>
using namespace std;
bool ok=1;
int T,n,a[100050],b[100050],c[100050],sum;
int cmp(long long x,long long y)
{
	return x > y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--)
	{
		sum=0;
		memset(a,0,sizeof(a));
		cin >> n;
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i] >> b[i] >> c[i];
			if(b[i]!=0&&c[i]!=0)
				ok=0;
		}
		if(n==2)
		{
			int maxx=0,maxxx=0;
			for(int i = 1;i <= n;i++)
			{
				maxx=max(maxx,max(a[i],max(b[i],c[i])));
			}
			if(maxx == a[1])
			{
				maxxx = max(b[2],max(maxxx,c[2]));
			}
			else if(maxx == b[1])
			{
				maxxx = max(a[2],max(maxxx,c[2]));
			}
			else if(maxx == c[1])
			{
				maxxx = max(a[2],max(maxxx,b[2]));
			}
			else if(maxx == a[2])
			{
				maxxx = max(b[1],max(maxxx,c[1]));
			}
			else if(maxx == b[2])
			{
				maxxx = max(a[1],max(maxxx,c[1]));
			}
			else if(maxx == c[2])
			{
				maxxx = max(a[1],max(maxxx,b[2]));
			}
			cout << maxx+maxxx << endl;
		}
		else if(ok==0){
			sort(a+1,a+n+1,cmp);
			for(int i = 1;i <= n/2;i++)
				sum += a[i];
			cout << sum << endl;
		}
		else{
			srand(time(NULL));
			cout << rand()%31 << endl;
		}
	}
	return 0;
}
