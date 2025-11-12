#include <bits/stdc++.h>

using namespace std;
const int N=100010;
struct p{
    int r1,po1,r2,po2,e;
}a[N];
int t,n;
bool cmp(p x,p y){
    if(x.r1==y.r1){
        if(x.po1+y.po2>=x.po2+y.po1){
            return true;
        }else return false;
    }
    if(x.r2==y.r1)return false;
    if(x.r1==y.r2)return true;
    if(y.r2!=x.r1&&y.r2!=x.r2)return false;
    if(x.r1==x.r2)return false;
    return false;
}
void chuli(){
    for(int i=1;i<=n;i++){
        if(a[i].po1<a[i].po2){
            swap(a[i].po1,a[i].po2);
            swap(a[i].r1,a[i].r2);
        }
    }
}
int cnt[4],bh[N][4],yu[N][4];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1,x,y,z;i<=n;i++){
            cin>>x>>y>>z;
            yu[i][1]=x,yu[i][2]=y,yu[i][3]=z;
            if(x<=y&&x<=z){
                a[i]={2,y,3,z,i};
            }else if(y<=x&&y<=z){
                a[i]={1,x,3,z,i};
            }else a[i]={1,x,2,y,i};
        }
        chuli();
        sort(a+1,a+1+n,cmp);
        memset(cnt,0,sizeof(cnt));
        int ans=0;
        for(int i=1;i<=n;i++){
            if(cnt[a[i].r1]<n/2){
                cnt[a[i].r1]++;
                ans+=a[i].po1;
            }else{
                cnt[a[i].r2]++;
                ans+=a[i].po2;
            }
        }
        cout<<ans<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
