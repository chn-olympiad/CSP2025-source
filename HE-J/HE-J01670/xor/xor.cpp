#include<iostream> 
using namespace std;
int main()
{
	freopen("xor.in","w",stdin);
	freopen("xor.out","r",stdout);
	int n,k;
	cin >> n >> k;
	int a[n];
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	fclose(stdout);
	return 0;
}
