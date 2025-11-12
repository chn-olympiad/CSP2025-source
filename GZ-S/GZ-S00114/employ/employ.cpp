//GZ-S00114   遵义市第十二中学   唐小杰
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);

	int n,m,sum=0;
	cin>>n>>m;
	int r[n+1];
	string a;
	cin>>a;
	for(int i=0;i<n;i++)
	{
		cin>>r[i];
	}
	int s=a.length();
	int z[s+1];
	for(int i=0;i<s;i++)
	{
		z[i]=a[i];
		if(z[i]=='1')
		{
			sum++;
		}
	}
	cout<<sum;
	return 0;

	fclose(stdin);
	fclose(stdout);
}

