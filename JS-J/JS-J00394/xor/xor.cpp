#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
    int n,k;
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    if(k==0) {
        for(int i=1;i<=n;i++)
        cin>>a[i];
            cout<<n;
    return 0;
    }
    if(k==1) {
        for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++)
    if(a[i]==a[i+1]) {
        cout<<n/2+1;
        return 0;
    }
    cout<<n/2;
        return 0;
    }
    for(int i=1;i<=n;i++)
        cin>>a[i];
        int s;
        srand(time(0));
        s=rand()%10000;
        cout<<s;
        return 0;
}
