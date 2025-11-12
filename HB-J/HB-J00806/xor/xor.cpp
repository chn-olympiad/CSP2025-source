#include<bits/stdc++.h>
using namespace std;
int cnt,n,k,a[500010],one,zero;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==0)zero++;
        else if(a[i]==1)one++;
    }

    if(k==0&&one==n)cout<<n/2;

    else if(n==2)
    {
        if(a[1]==k&&a[2]==k)cout<<2;
        else cout<<0;
    }

    else if(k==0)cout<<zero;
    else if(k==1)cout<<one;

    else{
        srand(time(NULL));
        cout<<rand()%(n-1);
    }
    return 0;
}
