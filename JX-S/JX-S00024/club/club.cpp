#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    int n;
    int clubmax;
    int a1[10001],a2[10001],a3[10001],amax[10001],amax2[10001],amin[10001];
    int myd;
    int j;
    int maxx=0;
    cin>>t;
    for(int i=1;i<=t;i++){
        myd=0;
        maxx=0;
        cin>>n;
        if(n==2){
            for(int j=1;j<=n;j++){
                cin>>a1[j]>>a2[j]>>a3[j];
            }
            maxx=max(a1[1]+a2[2],a1[1]+a3[2]);
            maxx=max(maxx,a2[1]+a1[2]);
            maxx=max(maxx,a2[1]+a3[2]);
            maxx=max(maxx,a3[1]+a1[2]);
            maxx=max(maxx,a3[1]+a2[2]);
            cout<<maxx<<endl;
        }
    }
    return 0;
}
