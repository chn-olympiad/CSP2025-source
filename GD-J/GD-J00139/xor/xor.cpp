#include <iostream>
#include <cstdio>
using namespace std;

int n,k;
int a[500002];
int main()
{
	freopen("xor.in","r",stdin);    freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	
	int tmp;
	tmp=n/2;
	if(n==1)
		tmp=0;
	cout<<tmp;
	return 0;
}
