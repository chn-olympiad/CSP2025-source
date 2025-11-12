#include<bits/stdc++.h>
using namespace std;
struct node{
    int aa,bb,cc;
}a[100005];
bool cmp(node x,node y){
    return x.aa>y.aa;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    bool tsyl=true;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].aa>>a[i].bb>>a[i].cc;
            if(a[i].bb!=0||a[i].cc!=0) tsyl=false;
        }
        if(tsyl){
            int cnt=0;
            sort(a+1,a+1+n,cmp);
            for(int i=1;i<=n/2;i++){
                cnt+=a[i].aa;
            }
            cout<<cnt;
        }
        int cnta=0,cntb=0,cntc=0;
    }
}
