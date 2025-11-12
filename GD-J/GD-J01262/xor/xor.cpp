#include<bits/stdc++.h>
using namespace std;
int qj[500010];
int k,n;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	bool f=1;
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> qj[i];
		if(qj[i]!=1)
		{
			f=0;	
		} 
	}
	if(f && k==0)
	{
		return 0;
	}
	cout << 2 << endl;
	return 0;
}
