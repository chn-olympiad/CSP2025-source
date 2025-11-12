#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e6+400;

int a[N];
int n,k;
signed main ()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++){
    	cin>>a[i];
	}
	int s=0,m=0;
	int ans=0;
	for (int i=1;i<=n;i++){
		if (a[i]==1) s++;
		else m++;
	}
	if (s%2==1&&k==0) cout<<0;
	if (k==1) cout<<s;
	if (s%2==0&&k==0) cout<<m-1;
	return 0;
}

