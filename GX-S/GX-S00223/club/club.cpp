#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[10010],ans[10010],b,c;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int z=1;z<=t;z++){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b>>c;
        }

        sort(a+1,a+1+n);
        for(int j=n;j>n/2;j--)
           ans[z]+=a[j];
    }
    for(int i=1;i<=t;i++)
        cout<<ans[i];

    return 0;
}

