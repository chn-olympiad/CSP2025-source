#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][5],f[205][205][205];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        memset(f,0,sizeof(f));
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        int ans=0;
        if(n<=30){
            for(int e=1;e<=n;e++){
                for(int i=n/2;i>=0;i--){
                    for(int j=n/2;j>=0;j--){
                        for(int k=n/2;k>=0;k--){
                            if(i==0&&j==0&&k==0||i+j+k>n) continue;
                            if(i!=0) f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[e][1]);
                            if(j!=0) f[i][j][k]=max(f[i][j][k],f[i][j-1][k]+a[e][2]);
                            if(k!=0) f[i][j][k]=max(f[i][j][k],f[i][j][k-1]+a[e][3]);
                        }
                    }
                }
            }
            for(int i=0;i<=n/2;i++){
                for(int j=0;j<=n/2;j++){
                    int k=n-i-j;
                    ans=max(ans,f[i][j][k]);
                }
            }
            cout<<ans<<"\n";
        }else if(n>=30&&n<=200){
            for(int e=1;e<=n;e++){
                for(int i=n/2;i>=0;i--){
                    for(int j=n/2;j>=0;j--){
                        if(i==0&&j==0) continue;
                        if(i!=0) f[i][j][0]=max(f[i][j][0],f[i-1][j][0]+a[e][1]);
                        if(j!=0) f[i][j][0]=max(f[i][j][0],f[i][j-1][0]+a[e][2]);
                    }
                }
            }
            for(int i=0;i<=n/2;i++){
                int j=n-i;
                ans=max(ans,f[i][j][0]);
            }
            cout<<ans<<"\n";
        }else{
            int ans2=0,b[100005];
            for(int i=1;i<=n;i++) b[i]=a[i][1];
            sort(b+1,b+1+n);
            for(int i=n;i>=n/2+1;i--) ans2+=b[i];
            cout<<ans2<<"\n";
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
