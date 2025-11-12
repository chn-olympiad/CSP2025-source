#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    int j;

    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==k)
        {
            j++;
        }
    }
    cout <<j;
    return 0;
}
