#include <bits/stdc++.h>
using namespace std;

bool B = true;
//bool C = true;
int ans,t,n;
int sum[10005]; 
int a[10005],b[10005],c[10005];

struct member:
{
	int a;
	int b;
	int c;
	int position;	
};
member members[10005];

bool cmp(int x,int y)
{
	return x > y;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin >> t;
	for(int i = 0;i < t;++i)
	{
		cin >> n;
		for(int j = 0;j < n;++j)
		{
			cin >> a[j] >> b[j] >> c[j];
		}
		
		for(int j = 0;j < n;++j)
		{
			if(c[j] != 0)
			{
				C = false;
			}
			if(b[j] != 0 || !C )
			{
				B = false;
			}
		}
		if(B)
		{
			sort(a,a + n,cmp);
			for(int j = 0;j < n / 2;++j)
			{
				ans += a[j]; 
			}
			cout << ans << endl;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
