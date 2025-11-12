#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
struct nx{
    int ngm[4],bm,zd;
}a[100005];
int cmp(nx m,nx n){
    if(m.bm==n.bm){
        return m.zd>n.zd;
    }
    return m.zd<n.zd;
}
int cmp2(nx m,nx n){
    if(m.bm!=n.bm){
        return m.zd>n.zd;
    }
    return m.zd<n.zd;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n;
    cin>>t;
    while(t--){
        int cnm[4]={0,0,0,0},sum=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].ngm[1]>>a[i].ngm[2]>>a[i].ngm[3];
            if(a[i].ngm[1]<a[i].ngm[2]){
                if(a[i].ngm[2]<a[i].ngm[3]){
                    a[i].bm=3;
                }
                else{
                    a[i].bm=2;
                }
            }
            else{
                if(a[i].ngm[1]<a[i].ngm[3]){
                    a[i].bm=3;
                }
                else{
                    a[i].bm=1;
                }
            }
            a[i].zd=max(max(a[i].ngm[1],a[i].ngm[2]),a[i].ngm[3]);
        }
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++){
            if(cnm[a[i].bm]<n/2){
                sum+=a[i].zd;
            }
            else{
                if(a[i].bm==3){
                    a[i].bm=2;
                    sum+=max(a[i].ngm[a[i].bm-1],a[i].ngm[a[i].bm]);
                    a[i].bm=3;
                }
                else if(a[i].bm==2){
                    sum+=max(a[i].ngm[a[i].bm-1],a[i].ngm[a[i].bm+1]);
                }
                else{
                    a[i].bm=2;
                    sum+=max(a[i].ngm[a[i].bm],a[i].ngm[a[i].bm+1]);
                    a[i].bm=1;
                }
            }
            cnm[a[i].bm]++;
        }
        sort(a+1,a+n+1,cmp2);
        int sum2=0;
        int cnm2[4]={0,0,0,0};
        for(int i=1;i<=n;i++){
            if(cnm2[a[i].bm]<n/2){
                sum2+=a[i].zd;
            }
            else{
                if(a[i].bm==3){
                    a[i].bm=2;
                    sum2+=max(a[i].ngm[a[i].bm-1],a[i].ngm[a[i].bm]);
                    a[i].bm=3;
                }
                else if(a[i].bm==2){
                    sum2+=max(a[i].ngm[a[i].bm-1],a[i].ngm[a[i].bm+1]);
                }
                else{
                    a[i].bm=2;
                    sum2+=max(a[i].ngm[a[i].bm],a[i].ngm[a[i].bm+1]);
                    a[i].bm=1;
                }
            }
            cnm2[a[i].bm]++;
        }
        sum=max(sum,sum2);
        cout<<sum<<endl;
    }
    return 0;
}
