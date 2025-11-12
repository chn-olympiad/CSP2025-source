#include<iostream>
#include<algorithm>
#include<map>
#include<cstring>
using namespace std;
int t;
int n;
struct node{
    int x,y,z,ok;
}a[100005],b[100005];
bool cmp(node p,node q){
    return max({p.x,p.y,p.z})>max({q.x,q.y,q.z});
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        int limit[4]={0,n/2,n/2,n/2};// <=
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
            a[i].ok=1;
        }
        memcpy(b,a,sizeof(a));
        int ans=0;
        sort(a+1,a+1+n,cmp);
        for(int i=1;i<=n;i++){
             int ma=0,pos=0;
            //cout<<a[i].x<<' '<<a[i].y<<' '<<a[i].z<<endl;
            if(a[i].x>a[i].y&&a[i].x>a[i].z){
                if(limit[1]>0){
                    ma=a[i].x;
                    a[i].ok=0;
                    limit[1]--;
                    pos=1;
                }else{//limit2[1]==0
                    if(a[i].y>a[i].z&&limit[2]>0){
                        ma=a[i].y;
                        a[i].ok=0;
                        limit[2]--;
                        pos=2;
                    }else if(limit[3]>0){
                        ma=a[i].z;
                        a[i].ok=0;
                        limit[3]--;
                        pos=3;
                    }
                }
            }else if(a[i].y>a[i].x&&a[i].y>a[i].z){
                if(limit[2]>0){
                    ma=a[i].y;
                    a[i].ok=0;
                    limit[2]--;
                    pos=2;
                }else if(limit[3]>0){
                    ma=a[i].z;
                    a[i].ok=0;
                    limit[3]--;
                    pos=3;
                }
            }else if(a[i].z>a[i].x&&a[i].z>a[i].y){
                if(limit[3]>0){
                    ma=b[i].z;
                    b[i].ok=0;
                    limit[3]--;
                    pos=3;
                }
            }
            ans+=ma;
        }
        //
        int ans2=0;
        int limit2[4]={0,n/2,n/2,n/2};
        sort(b+1,b+1+n,cmp);
        for(int i=n;i>=1;i--){
             int ma=0,pos=0;
            //cout<<a[i].x<<' '<<a[i].y<<' '<<a[i].z<<endl;
            if(b[i].x>b[i].y&&b[i].x>b[i].z){
                if(limit2[1]>0){
                    ma=b[i].x;
                    b[i].ok=0;
                    limit2[1]--;
                    pos=1;
                }else{//limit2[1]==0
                    if(b[i].y>b[i].z&&limit2[2]>0){
                        ma=b[i].y;
                        b[i].ok=0;
                        limit2[2]--;
                        pos=2;
                    }else if(limit2[3]>0){
                        ma=b[i].z;
                        b[i].ok=0;
                        limit2[3]--;
                        pos=3;
                    }
                }
            }else if(b[i].y>b[i].x&&b[i].y>b[i].z){
                if(limit2[2]>0){
                    ma=b[i].y;
                    b[i].ok=0;
                    limit2[2]--;
                    pos=2;
                }else if(limit2[3]>0){
                    ma=b[i].z;
                    b[i].ok=0;
                    limit2[3]--;
                    pos=3;
                }
            }else if(b[i].z>b[i].x&&b[i].z>b[i].y){
                if(limit2[3]>0){
                    ma=b[i].z;
                    b[i].ok=0;
                    limit2[3]--;
                    pos=3;
                }
            }
            ans2+=ma;
        }
//        cout<<ans2<<endl;;
        //
        ans=max(ans,ans2);
        cout<<ans<<endl;
    }
    return 0;
}
