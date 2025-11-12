#include <bits/stdc++.h>
using namespace std;
int t;
int op[2005]={0};
struct node{
    int x,num;
};
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[3*n+1];
        for(int i=1;i<=n*3;i+=3){
            cin>>a[i]>>a[i+1]>>a[i+2];
        }
        sort(a+1,a+1+n*3);
        int ans=0;
        for(int i=n*3;i>=n*3-n+1;i--){
            ans+=a[i];
        }
        cout<<ans<<"\n";
    }

    return 0;
}
