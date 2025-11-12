#include<bits/stdc++.h>
using namespace std;
int a[105],s[15][15];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m,f,cnt=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	f=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i%2==0)
			{
				s[n-j+1][i]=a[cnt];
			}
			else
			{
				s[j][i]=a[cnt];
			}
			cnt++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
//			cout<<s[i][j]<<" ";
			if(s[i][j]==f)
			{
				cout<<j<<" "<<i<<endl;
				return 0;
			}
		}
//		cout<<endl;
	}
	
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
