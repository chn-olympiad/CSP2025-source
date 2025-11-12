#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[N],b,c;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b>>c;
        }
        int ans=0;
        sort(a+1,a+1+n,cmp);
        for(int i=1;i<=n/2;i++){
            ans+=a[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
