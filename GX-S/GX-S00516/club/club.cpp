#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
int a[N],b[N],c[N];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;cin>>T;
    while(T--){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        cin>>n;
        bool ff=1;
        int cnt=0;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            if(b[i]!=0){
                ff=0;
            }
        }
        if(n==2){
            cnt+=max(a[1],max(b[1],c[1]));
            cnt+=max(a[2],max(b[2],c[2]));
            cout<<cnt;continue;
        }
        if(ff){
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n/2;i++){
            cnt+=a[i];
        }
        cout<<cnt;
        continue;
        }
    }
    return 0;
}
