#include <bits/stdc++.h>
using namespace std;
int a[100010][10];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ans=0,cnt[3]={};
        for(int i=1;i<=n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            int x=a[i][0],y=a[i][1],z=a[i][2];
            if(x>=y){
                if(x>=z){
                    a[i][3]=0,a[i][4]=a[i][0];
                    if(y>=z){
                        a[i][5]=1,a[i][6]=y;a[i][7]=2,a[i][8]=z;
                    }else{
                        a[i][5]=2,a[i][6]=z;a[i][7]=1,a[i][8]=y;
                    }
                }else{
                    a[i][3]=2,a[i][4]=z;a[i][5]=0,a[i][6]=x;a[i][7]=1,a[i][8]=y;
                }
            }else{
                if(z<y){
                    a[i][3]=1,a[i][4]=a[i][1];
                    if(x>=z){
                        a[i][5]=0,a[i][6]=x;a[i][7]=2,a[i][8]=z;
                    }else{
                        a[i][5]=2,a[i][6]=z;a[i][7]=0,a[i][8]=x;
                    }
                }else{
                    a[i][3]=2,a[i][4]=z;a[i][5]=1,a[i][6]=y;a[i][7]=0,a[i][8]=x;
                }
            }
            cnt[a[i][3]]++;
        }//
        if(cnt[0]>n/2){
            bool flag[n+10]={};
                    int m=0,k=0;
                    for(int i=1;i<=n/2;i++){
                        for(int j=1;j<=n;j++){
                            if(a[j][3]==0&&flag[j]==0){
                                if(a[j][4]>m){
                                    m=a[j][4];
                                    k=j;
                                }
                            }
                        }
                        ans+=m;
                        flag[k]=1;
                    }
                    cnt[0]=n/2;
                    for(int i=1;i<=n;i++){
                        if(!flag[i]){
                            a[i][3]=a[i][5];a[i][4]=a[i][6];a[i][5]=a[i][7];a[i][6]=a[i][8];
                            cnt[a[i][3]]++;
                        }
                    }
        }
        else if(cnt[1]>n/2){
            bool flag[n+10]={};
                    int m=0,k=0;
                    for(int i=1;i<=n/2;i++){
                        for(int j=1;j<=n;j++){
                            if(a[j][3]==1&&flag[j]==0){
                                if(a[j][4]>m){
                                    m=a[j][4];
                                    k=j;
                                }
                            }
                        }
                        ans+=m;
                        flag[k]=1;
                    }
                    cnt[1]=n/2;
                    for(int i=1;i<=n;i++){
                        if(!flag[i]){
                            a[i][3]=a[i][5];a[i][4]=a[i][6];a[i][5]=a[i][7];a[i][6]=a[i][8];
                            cnt[a[i][3]]++;
                        }
                    }
        }
        else if(cnt[2]>n/2){
            bool flag[n+10]={};
                    int m=0,k=0;
                    for(int i=1;i<=n/2;i++){
                        for(int j=1;j<=n;j++){
                            if(a[j][3]==2&&flag[j]==0){
                                if(a[j][4]>m){
                                    m=a[j][4];
                                    k=j;
                                }
                            }
                        }
                        ans+=m;
                        flag[k]=1;
                    }
                    cnt[2]=n/2;
                    for(int i=1;i<=n;i++){
                        if(!flag[i]){
                            a[i][3]=a[i][5];a[i][4]=a[i][6];a[i][5]=a[i][7];a[i][6]=a[i][8];
                            cnt[a[i][3]]++;
                        }
                    }
        }
        else{
            for(int i=1;i<=n;i++){
                ans+=a[i][4];
            }
        }
        if(n==2){
            ans=max(a[2][4]+a[1][6],a[2][6]+a[1][4]);
        }
        cout<<ans;
    }
    return 0;
}
