#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int a[100005],b[100005],c[100005];
        for(int i=0;i<n;i++){
            cin>>a[i]>>b[i]>>c[i];
        }
        sort(a,a+n);
        int sumn=0;
        for(int i=n;i>=n/2;i--){
            sumn+=a[i];
        }
        cout<<sumn<<endl;
    }
    return 0;
}
