#include<bits/stdc++.h>
using namespace std;
const int N=2*1e4+3;
int a[N],b[N],c[N];
int n;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        int ans=0;
        for(int i=0;i<n;i++){
            cin>>a[i]>>b[i]>>c[i];
            a[i]-=b[i];
            ans+=b[i];
        }
        sort(a,a+n,cmp);
        for(int i=0;i<n/2;i++){
            ans+=a[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
