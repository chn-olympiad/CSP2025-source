#include<bits/stdc++.h>
int a,n;
long long m[100000][3],s=0;
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>a;
	for(int k=1;k<=a;k++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>m[i][j];
			}
		}
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(m[j][1]<m[j+1][1])
				{
					swap(m[j][1],m[j+1][1]);
				}
			}
		}
		for(int i=1;i<=n/2;i++)
		{
			s=s+m[i][1];
		}
		for(int i=n/2;i<=n;i++)
		{
			s=s+m[i][2];
		}
		cout<<s<<endl;
		s=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
