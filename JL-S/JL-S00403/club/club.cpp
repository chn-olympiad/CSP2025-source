#include<bits/stdc++.h>
using namespace std;
int ans,t,n,b,c,d;
const int N=3e5+10;
int a[N];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i+=3){
            cin>>a[i]>>a[i+1]>>a[i+2];
        }
        sort(a,a+n*3);
        for(int i=n*3-1;i>=n*2;i++){
            ans+=a[i];
        }
        cout<<ans<<endl;
    }

    return 0;
}
