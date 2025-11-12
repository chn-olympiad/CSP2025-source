#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,a[100010][3],b[4],l1[100010],l2[100010],l3[100010];
bool cmp(int x,int y){
    return x<y;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--){
        int p1=0,p2=0,p3=0,ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            int a1,a2,a3;
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            a1=a[i][0];
            a2=a[i][1];
            a3=a[i][2];
            for(int j=0;j<=2;j++){
                b[j+1]=a[i][j];
            }
            stable_sort(b+1,b+4);
            for(int j=0;j<=2;j++){
                a[i][j]=b[j+1];
                //cout<<a[i][j]<<" ";
            }
            int xx=a[i][2];
            if(xx==a1){
                if(p1+1<=(n/2)){
                    ans+=xx;
                    p1++;
                }
                else{
                    int yy=a[i][1];
                    if(yy==a2){
                        if(p2+1<=(n/2)){
                            p2++;
                            ans+=yy;
                        }
                        else{
                            p3++;
                            ans+=a[i][0];
                        }
                    }
                    else{
                        if(p3+1<=(n/2)){
                            p3++;
                            ans+=yy;
                        }
                        else{
                            p2++;
                            ans+=a[i][0];
                        }
                    }
                }
            }
            if(xx==a2){
                if(p2+1<=(n/2)){
                    ans+=xx;
                    p2++;
                }
                else{
                    int yy=a[i][1];
                    if(yy==a3){
                        if(p3+1<=(n/2)){
                            p3++;
                            ans+=yy;
                        }
                        else{
                            p1++;
                            ans+=a[i][0];
                        }
                    }
                    else{
                        if(p1+1<=(n/2)){
                            p1++;
                            ans+=yy;
                        }
                        else{
                            p3++;
                            ans+=a[i][0];
                        }
                    }
                }
            }
            if(xx==a3){
                if(p3+1<=(n/2)){
                    ans+=xx;
                    p3++;
                }
                else{
                    int yy=a[i][1];
                    if(yy==a2){
                        if(p2+1<=(n/2)){
                            p2++;
                            ans+=yy;
                        }
                        else{
                            p1++;
                            ans+=a[i][0];
                        }
                    }
                    else{
                        if(p1+1<=(n/2)){
                            p1++;
                            ans+=yy;
                        }
                        else{
                            p2++;
                            ans+=a[i][0];
                        }
                    }
                }
            }
            //cout<<ans<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}
