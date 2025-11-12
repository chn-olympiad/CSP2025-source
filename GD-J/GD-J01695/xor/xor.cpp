#include <bits/stdc++.h>
using namespace std;
const int N=5e5+9;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	if(k==0)
	{
		if(n%2==0)
		{
			cout<<n;
		}
		else
		{
			cout<<n-1;
		}
	}
	
	return 0;
}
