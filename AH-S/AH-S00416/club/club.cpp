#include <bits/stdc++.h>
using namespace std;
int a[100005][4],b[100005],c[100005],maxn[100005],k[100005];
int f[2][205][205],g[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--){
                int n;cin>>n;
        if(n==100000){
                memset(g,0,sizeof(g));
        memset(k,0,sizeof(k));
        memset(maxn,0,sizeof(maxn));
        int cnt1=0,ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
                if(a[i][j]>maxn[i]){
                    maxn[i]=a[i][j];
                    k[i]=j;
                }
            }
            g[k[i]]++;
            ans+=maxn[i];
        }int cnt2=0,kk=0;
        for(int i=1;i<=3;i++){
            if(g[i]>n/2){
                cnt2=g[i]-n/2;
                kk=i;
            }
        }
        for(int i=1;i<=n;i++){
            if(maxn[i]==a[i][kk]){
                for(int j=1;j<=3;j++){
                    if(j!=kk){
                        b[++cnt1]=maxn[i]-a[i][j];
                    }
                }
            }
        }
        sort(b+1,b+1+cnt1);
        for(int i=1;i<=min(cnt2,cnt1);i++){
            ans-=b[i];
        }
        cout<<ans<<"\n";continue;
            }
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=0;(j<=i)&&(j<=n/2);j++){
                for(int k=0;(k<=i)&&(k<=n/2);k++){
                    if(i-j-k>n/2) continue;
                    int s=i-j-k;
                    if(j+k>i) continue;
                     if(j>=1) f[i%2][j][k]=max(f[i%2][j][k],f[(i-1)%2][j-1][k]+a[i][1]);
                    if(k>=1) f[i%2][j][k]=max(f[i%2][j][k],f[(i-1)%2][j][k-1]+a[i][2]);
                    if(s>=1) f[i%2][j][k]=max(f[i%2][j][k],f[(i-1)%2][j][k]+a[i][3]);
                }
            }
        }//cout<<n<<"!!!";
        for(int i=0;i<=n/2;i++){
            //cout<<i<<"!!";
            for(int j=0;j<=n/2;j++){
                     if(n-j-i>n/2) continue;
                  //  cout<<n<<","<<i<<","<<j<<","<<n-i-j<<","<<"\n";
                ans=max(ans,f[n%2][i][j]);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
//Ren5Jie4Di4Ling5%
