#include<bits/stdc++.h>
using namespace std;
int n,T;
const int N=1e5+40;
long long a[N][10],b[N],f[N][2][2],ans,cnt;
int fr,s,t;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
                b[i]=a[i][1];
            }
        }
        sort(b+1,b+1+n,cmp);
        for(int i=1;i<=n/2;i++)
            ans+=b[i];
        cout<<ans<<endl;
        ans=0;
    }
    return 0;
}
