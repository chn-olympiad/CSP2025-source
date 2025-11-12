#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    long long n,k;
    long long a[n];
    int ans;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
	{
		if(a[i]==0)
		{
			cout<<1;
			return 0;
		}
	}
	cout<<0;
    fclose(stdin);
    fclose(stdout);
	return 0;
}
