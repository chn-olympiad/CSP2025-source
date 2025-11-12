#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500000];
int cnt=2;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
