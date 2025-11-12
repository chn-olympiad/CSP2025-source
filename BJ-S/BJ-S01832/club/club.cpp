#include<bits/stdc++.h>
using namespace std;
int t,n,ans,cnt;
int a[100010],b[100010],c[100010],co[4];
int x,y,z;
int r[5],s[5],t[5],u[5];
int main(){

    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        if(n>4){
            for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            if(b[i]==0&&c[i]==0){
                cnt++;
                }
            }
            if(cnt==n){
                sort(a+1,a+n+1);
                for(int i=1;i>=n/2;i++){
                    int j=n;
                    ans+=a[j];
                    j--;
                }
            }
            else{
                for(int i=1;i<=n;i++){
                    co[1]=a[i];
                    co[2]=b[i];
                    co[3]=c[i];
                    sort(co+1,co+4);
                    ans+=co[1];
                }
            }
        }

        if(n==2){

            cin>>x[1]>>x[2]>>x[3]>>y[1]>>y[2]>>y[3];
            ans=max(ans,x[1]+y[2]);
            ans=max(ans,x[1]+y[3]);
            ans=max(ans,x[2]+y[1]);
            ans=max(ans,x[2]+y[3]);
            ans=max(ans,x[3]+y[1]);
            ans=max(ans,x[3]+y[2]);
        }
        if(n==4){
            cin>>r[1]>>r[2]>>r[3]>>s[1]>>s[2]>>s[3]>>t[1]>>t[2]>>t[3]>>u[1]>>u[2]>>u[3];
            for(int i=1;i<=3;i++)
                for(int j=1;j<=3;j++)
                    for(int k=1;k<=3;k++)
                        for(int l=1;l<=3;l++){
                            if(i==1)  x++;
                            if(j==1)  x++;
                            if(k==1)  x++;
                            if(l==1)  x++;
                            if(i==2)  y++;
                            if(j==2)  y++;
                            if(k==2)  y++;
                            if(l==2)  y++;
                            if(i==3)  z++;
                            if(j==3)  z++;
                            if(k==3)  z++;
                            if(l==3)  z++;
                            if(x<=2&&y<=2&&z<=2){
                                ans=max(ans,r[i]+s[j]+t[k]+w[l]);
                            }
                        }

        }
    }
    cout<<ans;
    return 0;
}