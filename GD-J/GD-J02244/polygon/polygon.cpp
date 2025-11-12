#include<bits/stdc++.h>

using namespace std;

int n,a[5010];
bool t[5010];
long long ans;
void DFS(int k)
{
	if(k==n)
	{
		int ma=INT_MIN,sum=0;
		for(int i=0; i<n; i++)
		{
			if(t[i]==true)
			{
				ma=max(ma,a[i]);
				sum+=a[i];
			}
		}
		if(sum>2*ma)
		{
			ans=(ans+1)%998244353; 
		}
		return;
	}
	t[k]=true;
	DFS(k+1);
	t[k]=false;
	DFS(k+1);
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin >> n;
	for(int i=0; i<n; i++)
	{
		cin >> a[i];
	}
	DFS(0);
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
