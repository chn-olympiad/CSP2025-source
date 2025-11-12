#include<bits/stdc++.h>
using namespace std;
int n,T,n2,n4,sub1,sub2;
int f[201][201][201][4],a[100001][4],maxn,t[100001];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        n2=n/2;
        maxn=0;
        sub1=1,sub2=1;
        memset(f,0x80,sizeof f);
        memset(t,0,sizeof t);
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][2]!=0||a[i][3]!=0)sub1=0;
            if(a[i][3]!=0)sub2=0;
        }
        if(sub1){
            for(int i=1;i<=n;i++){
                t[i]=a[i][1];
            }
            sort(t+1,t+n+1,greater<int>());
            int ans=0;
            for(int i=1;i<=n2;i++){
                ans+=t[i];
            }
            cout<<ans<<'\n';
            continue;
        }
        f[0][0][0][1]=0;
        f[0][0][0][2]=0;
        f[0][0][0][3]=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=n2&&j<=i;j++){
                for(int k=0;k<=n2&&k+j<=i;k++){
                    if(j>0)f[i][j][k][1]=max(max(f[i-1][j-1][k][1]+a[i][1],f[i-1][j-1][k][2]+a[i][1]),f[i-1][j-1][k][3]+a[i][1]);
                    if(k>0)f[i][j][k][2]=max(max(f[i-1][j][k-1][1]+a[i][2],f[i-1][j][k-1][2]+a[i][2]),f[i-1][j][k-1][3]+a[i][2]);
                    if(i-j-k>0)f[i][j][k][3]=max(max(f[i-1][j][k][1]+a[i][3],f[i-1][j][k][2]+a[i][3]),f[i-1][j][k][3]+a[i][3]);
                    //cout<<f[i][j][k][1]<<','<<f[i][j][k][2]<<','<<f[i][j][k][3]<<"  ";
                }
                //cout<<endl;
            }
            //cout<<endl;
        }
        for(int i=1;i<=n2;i++)
            for(int j=1;j<=n2&&i+j<=n;j++)
                if(i+j>=n2)maxn=max(max(maxn,f[n][i][j][1]),max(f[n][i][j][2],f[n][i][j][3]));
        cout<<maxn<<'\n';
    }
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    return 0;
}
*/
