#include<bits/stdc++.h>
using namespace std;
const int N=1e6+6;
int n,m,k;
int ans=0,cnt=0;
int t[N];
struct node{
    int x,y,w;
}a[N];
int c[15],b[15][N];
bool cmp(node x,node y){
    return x.w>y.w;
}
int check(int num){
    if(num==t[num])return num;
    return t[num]=check(t[num]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>a[i].x>>a[i].y>>a[i].w;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>b[i][j];

        }
    }
    for(int i=1;i<=m;i++)t[i]=i;
    sort(a+1,a+m+k+1,cmp);
    for(int i=1;i<=m/2;i++){
        int r1=check(a[i].x),r2=check(a[i].y);
        if(r1!=r2){
            //a[r1].x=a[r2].y;
            t[r1]=t[r2];
            int res=a[i].w;
            cnt++;
            //cout<<a[i].x<<"----"<<a[i].y<<"\n";
            if(k!=0){
                for(int p=1;p<=k;p++){
                    int bos=c[p];
                    for(int j=1;j<=n;j++){
                        if(j==a[p].x||j==a[p].y){
                            bos=bos+b[p][j];
                            //cout<<bos<<"-----"<<p<<"-----"<<j<<"\n";
                        }
                    }
                    //cout<<res<<"-----"<<bos<<"\n";
                    res=min(res,bos);
                }
            }
            ans+=res;
            //cout<<a[i].w<<"-----"<<a[i].x<<"----"<<a[i].y<<"\n";
        }
    }
    cout<<ans;
    return 0;
}
