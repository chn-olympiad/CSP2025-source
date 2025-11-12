#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n,p=1,l,h=1;
    int m;
    cin>>n;
    int a[10000],b[1000];
    for(int i=1;i<=n;i++){
        cin>>m;
        for(int j=1;j<=m*3;j++){
            cin>>a[j];
        }
        for(int j=1;j<=m*3;j+=3){
            b[h]=a[j];
            h++;
        }
        sort(b,b+h);
        int ans=0;
        for(int j=h;j>h/2;j--){
            ans=ans+b[j];
        }
        cout<<ans<<endl;
    }
    return 0;
}
