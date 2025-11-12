#include<bits/stdc++.h>
using namespace std;
struct s{
    int r1,r2,r3,m;
    bool operator<(const s&w){
        return r1>w.r1;
    }
}a[100005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int d=n/2;
        int f=0;
        for(int i=1;i<=n;i++){
            cin>>a[i].r1>>a[i].r2>>a[i].r3;
        }
        sort(a+1,a+1+n);
        for(int i=1;i<=d;i++){
            f+=a[i].r1;
        }
        cout<<f<<endl;
    }
    return 0;
}
