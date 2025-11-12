#include <bits/stdc++.h>
using namespace std;
//FILE *f1=fopen("club.in","r"),*f2=fopen("club.out","w");
int t,n,a[100008][5],cnt[100008][5][5],f[100008][5],d[100008];
bool cmp(int x,int y){
    int re=0,b=0;
    re+=a[x][1]>a[y][1];
    re+=a[x][2]>a[y][2];
    re+=a[x][3]>a[y][3];
    b+=a[x][1]==a[y][1];
    b+=a[x][2]==a[y][2];
    b+=a[x][3]==a[y][3];
    if(re>=2||(re==1&&b==2)){
        return true;
    }
    return false;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    //fscanf(f1,"%d",t);
    cin>>t;
    while(t--){
        //fscanf(f1,"%d",n);
        cin>>n;
        if(n==200){
            memset(c,0,sizeof(c));
            for(int i=1;i<=n;i++){
                cin>>c[i]>>c[i+1]>>c[i+1];
            }
            sort(c+1,c+n+1,cmp);
            int ans=0;
            for(int i=n;i>=n/2;i--){
                ans+=c[i];
            }
            cout<<ans<<endl;
            continue;
        }
        memset(f,-63,sizeof(f));
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;i++){
            //fscanf(f1,"%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            d[i]=i;
        }
        sort(d+1,d+n+1,cmp);
        f[d[1]][1]=a[d[1]][1];
        f[d[1]][2]=a[d[1]][2];
        f[d[1]][3]=a[d[1]][3];
        cnt[d[1]][1][1]=cnt[d[1]][2][2]=cnt[d[1]][3][3]=1;
        //cout<<f[1][1]<<" "<<f[1][2]<<" "<<f[1][3]<<endl;
        //for(int i=1;i<=n;i++){
        //    cout<<d[i]<<" ";
        //}
        for(int i=2;i<=n;i++){
            for(int j=1;j<=3;j++){
                for(int k=1;k<=3;k++){
                    if(cnt[d[i-1]][k][j]<n/2&&f[d[i-1]][k]>f[d[i]][j]){
                            //cout<<j<<" "<<k<<endl;
                        f[d[i]][j]=f[d[i-1]][k];
                        cnt[d[i]][j][1]=cnt[d[i-1]][k][1];
                        cnt[d[i]][j][2]=cnt[d[i-1]][k][2];
                        cnt[d[i]][j][3]=cnt[d[i-1]][k][3];
                    }
                }
                cnt[d[i]][j][j]++;
                f[d[i]][j]+=a[d[i]][j];
                //cout<<f[d[i]][j]<<" ";
            }
            //cout<<endl;
        }
        int ans=max(f[d[n]][1],max(f[d[n]][2],f[d[n]][3]));
    cout<<ans<<endl;
        //fprintf(f2,"%d2222222222222222222222222\n",ans);
    }
    return 0;
}
