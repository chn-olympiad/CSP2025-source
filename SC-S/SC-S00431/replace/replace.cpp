#include<bits/stdc++.h>
using namespace std;
const int k=1e8+10;
string a,b;
char c[k],d[k];

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);	
	long long n,m,sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>c[i]>>d[i];
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b;
		for(int j=1;j<=n;j++)
		{
			if(c[j]==a[i] || d[j]==b[i])
				sum++;
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}