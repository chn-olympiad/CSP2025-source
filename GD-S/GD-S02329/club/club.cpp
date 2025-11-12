#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,a[maxn][3];
namespace sl1{
    //n<=200, 55pts
    const int maxm=200+5;
    int f[maxm][maxm][maxm];
    void sl(){
        memset(f,0,sizeof(f));
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                for(int k=0;j+k<=i;k++){
                    f[i+1][j+1][k]=max(f[i+1][j+1][k],f[i][j][k]+a[i+1][0]);
                    f[i+1][j][k+1]=max(f[i+1][j][k+1],f[i][j][k]+a[i+1][1]);
                    f[i+1][j][k]=max(f[i+1][j][k],f[i][j][k]+a[i+1][2]);
                }
            }
        }
        int res=0;
        for(int j=0;j<=n/2;j++){
            for(int k=0;k<=n/2;k++){
                if(j+k>=n/2){
                    res=max(res,f[n][j][k]);
                }
            }
        }
        cout<<res<<'\n';
    }
}
namespace sl2{
    // n<=1e5, 正解……吗?
    int cnt[3],ch[maxn],b[maxn];
    int renew(int pos){
        int tt=0,res2=0;
        for(int i=1;i<=n;i++){
            if(ch[i]==pos){
                b[++tt]=min(a[i][pos]-a[i][(pos+1)%3],a[i][pos]-a[i][(pos+2)%3]);
            }
        }
        sort(b+1,b+tt+1);
        for(int i=1;i<=cnt[pos]-n/2;i++){
            res2+=b[i];
        }
        return res2;
    }
    void sl(){
        int res1=0;
        cnt[0]=cnt[1]=cnt[2]=0;
        for(int i=1;i<=n;i++){
            int mx=0,pos=0;
            for(int j=0;j<=2;j++){
                if(a[i][j]>mx){
                    mx=a[i][j],ch[i]=j;
                }
            }
            res1+=mx,cnt[ch[i]]++;
        }
        if(cnt[0]>n/2){
            res1-=renew(0);
        }
        else if(cnt[1]>n/2){
            res1-=renew(1);
        }
        else if(cnt[2]>n/2){
            res1-=renew(2);
        }
        cout<<res1<<'\n';
    }
}
void Main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i][0]>>a[i][1]>>a[i][2];
    }
    if(n<=200){
        sl1::sl();
    }
    else{
        sl2::sl();
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        Main();
    }
}