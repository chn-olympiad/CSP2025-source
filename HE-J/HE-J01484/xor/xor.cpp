#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[1100],tot=0;
	cin>>n>>k;
	if (k==0)
	{
		for (int i=1;i<=n;i++)
		{
			cin>>a[i];
			if (a[i]==0) tot++;
		}
		cout<<tot<<endl;
	}else if(k==1){
		for (int i=1;i<=n;i++)
		{
			cin>>a[i];
			if (a[i]==1) tot++;
		}
		cout<<tot<<endl;
	}
	return 0;
}
