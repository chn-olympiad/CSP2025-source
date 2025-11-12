#include<bits/stdc++.h>
using namespace std;
int n,t;
int ans;
int a[100001][4];
int b[100001];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int k=1;k<=t;k++){
        cin>>n;
        ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
                b[i]=a[i][1];
            }
        }
        sort(b+1,b+1+n);
        for(int i=n;i>n/2;i--)ans+=b[i];
        cout<<ans<<endl;
    }
    return 0;
}
