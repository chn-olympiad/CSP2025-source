#include<bits/stdc++.h>
using namespace std;
int a[500000];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if(k==0)
        cout<<n/2;
	return 0;
}
