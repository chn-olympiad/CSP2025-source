#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        long long n,a[4]={0},sum=0,maxn=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[1]>>a[2]>>a[3];
            maxn=max(a[1],max(a[2],a[3]));
            sum+=maxn;
        }
        cout<<sum<<endl;
    }
    return 0;
}
