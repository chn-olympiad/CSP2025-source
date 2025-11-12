#include<bits/c++.h>
using namespace std;
int n,a[5005],sum,maxn;
void ans (int x)
{ 
	if (x>3||x==3)
	{
		sum +=x;
	}
	if(x>maxn)
	{
		x=maxn;
	}
	int main()
	{
		cin >>n;
		for (int i=1;i<=n;i++)
		{
			cin >>a[i];
		}
		
		
		
		if (sum >2*maxn)
		{
			ans++;
		}
	cout << ans <<endl;
	return 0;
}
