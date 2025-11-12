#include<bits/stdc++.h>
using namespace std;
struct club{
    int x,y,z;
    int maxn;
    int maxm;
}a[100010];
bool cmp(club a,club b){
    return a.maxn>=b.maxn;
}
int main(){
    ios::sync_with_stdio(false);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T,n,ans=0,bns=0,cns=0,alll=0;
    cin>>T;
    for(int l=1;l<=T;l++){
        cin>>n;
        ans=0;
        bns=0;
        cns=0;
        alll=0;
        for(int i=1;i<=n;i++){
            cin>>a[i].x;
            cin>>a[i].y;
            cin>>a[i].z;
            if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
                a[i].maxn=a[i].x;
                a[i].maxm=1;
            }
            if(a[i].y>=a[i].x&&a[i].y>=a[i].z){
                a[i].maxn=a[i].y;
                a[i].maxm=2;
            }
            if(a[i].z>=a[i].y&&a[i].z>=a[i].x){
                a[i].maxn=a[i].z;
                a[i].maxm=3;
            }
        }
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++){
            if(a[i].maxm==1){
                if(ans<n/2){
                    alll+=a[i].maxn;
                    ans++;
                    continue;
                }
                else{
                    if(a[i].y>a[i].z){
                        alll+=a[i].y;
                    }
                    else{
                        alll+=a[i].z;
                    }
                }
            }
            if(a[i].maxm==2){
                if(bns<n/2){
                    alll+=a[i].maxn;
                    bns++;
                    continue;
                }
                else{
                    if(a[i].x>a[i].z){
                        alll+=a[i].x;

                    }
                    else{
                        alll+=a[i].z;
                    }
                }
            }
            if(a[i].maxm==3){
                if(cns<n/2){
                    alll+=a[i].maxn;
                    cns++;
                    continue;
                }
                else{
                    if(a[i].x>a[i].y){
                        alll+=a[i].x;
                    }
                    else{
                        alll+=a[i].y;
                    }
                }
            }
        }
        cout<<alll<<endl;
        for(int i=1;i<=n;i++){
            a[i].x=0;
            a[i].y=0;
            a[i].z=0;
            a[i].maxn=0;
            a[i].maxm=0;
        }
    }
    return 0;
}
