#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n,t,a[N][5],dp[N];
bool flag;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        flag=0;
        //16~27 tA
        for(int i=1;i<=n;i++){
                cin>>a[i][1]>>a[i][2]>>a[i][3];
                if(a[i][2]!=0||a[i][3]!=0) flag=1;
        }
        if(!flag){
            int  b[N],ans=0;
            for(int i=1;i<=n;i++) b[i]=a[i][1];
            sort(b+1,b+n+1,cmp);
            for(int i=1;i<=n/2;i++) ans+=b[i];
            cout<<ans<<endl;
        }
        if(n==2) {
            cout<<max(a[1][1]+a[2][1],a[1][2]+a[2][1]);
        }
        else if(n==4){

        }
    }
    return 0;
}
