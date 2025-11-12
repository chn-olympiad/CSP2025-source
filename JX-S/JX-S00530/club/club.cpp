#include<bits/stdc++.h>
using namespace std;
struct ru{
    int x,y,z;
    int ma,mc;
    int yl;
}a[200010];
int n;
bool cmp(ru x,ru y){
    if(x.ma!=y.ma)  return x.ma>y.ma;
    else{
        if(x.x+x.y+x.z-x.ma!=y.x+y.y+y.z-y.ma){
            return x.x+x.y+x.z-x.ma>y.x+y.y+y.z-y.ma;
        }
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int m;
    scanf("%d",&m);
    while(m--){
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        int tsA=0,tsB=0;
        for(int i=1;i<=n;i++){
            int x,y,z;
            scanf("%d %d %d",&x,&y,&z);
            if(z!=0) tsB=tsA=1;
            if(y!=0) tsA=1;
            a[i]={x,y,z,max(x,max(y,z)),0,i};
            if(x>=y){
                if(x>=z){
                    a[i].mc=1;
                }else if(z>=x){
                    a[i].mc=3;
                }
            }else if(x>=z){
                if(x>=y){
                    a[i].mc=1;
                }else if(y>=x){
                    a[i].mc=2;
                }
            }else{
                if(y>=z){
                    a[i].mc=2;
                }else{
                    a[i].mc=3;
                }
            }
        }
        sort(a+1,a+n+1,cmp);
        /*
        for(int i=1;i<=n;i++){
            cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<" "<<a[i].ma<<" "<<a[i].mc<<" "<<a[i].yl<<endl;
        }
        */
        int rl[4]={0,0,0,0};
        for(int i=1;i<=n;i++){
            if(rl[a[i].mc]<n/2){
                rl[a[i].mc]++;
                rl[0]+=a[i].ma;
            }else{
                if(a[i].mc==1){
                    if(a[i].y>a[i].z&&rl[2]<n/2){
                        rl[2]++;
                        rl[0]+=a[i].y;
                    }else if(a[i].z>a[i].y&&rl[3]<n/2){
                        rl[3]++;
                        rl[0]+=a[i].z;
                    }else{
                        if(rl[2]<=rl[3]){
                            rl[2]++;
                            rl[0]+=a[i].y;
                        }else{
                            rl[3]++;
                            rl[0]+=a[i].z;
                        }
                    }
                }else if(a[i].mc==2){
                    if(a[i].x>a[i].z&&rl[1]<n/2){
                        rl[1]++;
                        rl[0]+=a[i].x;
                    }else if(a[i].z>a[i].x&&rl[3]<n/2){
                        rl[3]++;
                        rl[0]+=a[i].z;
                    }else{
                        if(rl[1]<=rl[3]){
                            rl[1]++;
                            rl[0]+=a[i].x;
                        }else{
                            rl[3]++;
                            rl[0]+=a[i].z;
                        }
                    }
                }else if(a[i].mc==3){
                    if(a[i].x>a[i].y&&rl[1]<n/2){
                        rl[1]++;
                        rl[0]+=a[i].x;
                    }else if(a[i].y>a[i].x&&rl[2]<n/2){
                        rl[2]++;
                        rl[0]+=a[i].y;
                    }else{
                        if(rl[1]<=rl[2]){
                            rl[1]++;
                            rl[0]+=a[i].x;
                        }else{
                            rl[2]++;
                            rl[0]+=a[i].y;
                        }
                    }
                }
            }
        }
        cout<<rl[0]<<endl;
    }
    return 0;
}
