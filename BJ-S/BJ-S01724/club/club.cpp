#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
//int dp[N][4],a[N][4];
struct Node{
    int val,id;
}a[4];
int num[4];
int b[N],c[N],d[N];
bool cmp(Node x,Node y){
    return x.val>y.val;
}
void work(){
    //cout<<'a'<<endl;
    int n,x,y,z,ans=0,cha,nn=0,bp=0,cp=0,dp=0;
    num[1]=num[2]=num[3]=0;
    cin>>n;
    for(int i=1;i<=n;++i){
            cin>>x>>y>>z;
            a[1].id=1,a[1].val=x;
            a[2].id=2,a[2].val=y;
            a[3].id=3,a[3].val=z;
            sort(a+1,a+4,cmp);
            num[a[1].id]++;
            if(a[1].id==1) b[++bp]=a[1].val-a[2].val;
            if(a[1].id==2) c[++cp]=a[1].val-a[2].val;
            if(a[1].id==3) d[++dp]=a[1].val-a[2].val;

            ans+=a[1].val;
            //cout<<ans<<endl;
    }
    sort(b+1,b+bp+1);
    sort(c+1,c+cp+1);
    sort(d+1,d+dp+1);
    if(num[1]<=n/2&&num[2]<=n/2&&num[3]<=n/2){
        cout<<ans<<endl;
        return ;
    }
    if(num[1]>n/2){
        cha=num[1]-(n/2);
        for(int i=1;i<=cha;++i) nn+=b[i];
        cout<<ans-nn<<endl;
    }
    if(num[2]>n/2){
        cha=num[2]-(n/2);
        for(int i=1;i<=cha;++i) nn+=c[i];
        cout<<ans-nn<<endl;
    }
    if(num[3]>n/2){
        cha=num[3]-(n/2);
        for(int i=1;i<=cha;++i) nn+=d[i];
        cout<<ans-nn<<endl;
    }
    return ;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        work();
    }
    return 0;
}
