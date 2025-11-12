#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[10005],b[10005],c[10005],x,y,z;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        for(int j=1;j<=n;j++){
            cin>>a[j]>>b[j]>>c[j];
        }
    }
    int cnt,ls;
    for(int i=1;i<=t;i++){
        for(int j=1;j<=n;j++){
            ls=max(a[j],max(b[j],c[j]));
            cnt+=ls;
        }
        cout<<ls<<endl;
    }
    return 0;
}
