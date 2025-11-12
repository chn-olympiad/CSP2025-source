#include<iostream>
#include<cstdio>
using namespace std;
long long a[5005];

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	long long maxn=0,sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
		sum+=a[i];
	}
	if(sum>2*maxn) cout<<"1"<<endl;
	else cout<<"0"<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
