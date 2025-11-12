#include<bits/stdc++.h>

using namespace std;

int n,m,a[1010],w,g,k;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin >> n >> m;
	for(int i=0; i<n*m-1; i++) cin >> a[i];
	g=a[0];
	sort(a,a+n*m);
	for(int i=0; i<n*m-1; i++)
	{
		if(g==a[i]) w=n*m-i;
	}
	for(int i=0; i<m; i++)
	{
		if(i%2==0)
		{
			for(int j=0; j<n; j++)
			{
				k++;
				if(k==w) cout << i+1 << " " << j+1 << endl;
			}
		}
		else
		{
			for(int j=n-1; j>=0; j--)
			{
				k++;
				if(k==w) cout << i+1 << " " << j+1 << endl; 
			}
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
