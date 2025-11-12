#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N][5];
int b[N],c[N],d[N];
bool cmp1(int x,int y){
    int xx,yy;
    if(a[x][2]>a[x][3]) xx=2;
    else xx=3;
    if(a[y][2]>a[y][3]) yy=2;
    else yy=3;
    if(a[x][1]-a[x][xx]>a[y][1]-a[y][yy]) return true;
    else return false;
}
bool cmp2(int x,int y){
    int xx,yy;
    if(a[x][1]>a[x][3]) xx=1;
    else xx=3;
    if(a[y][1]>a[y][3]) yy=1;
    else yy=3;
    if(a[x][2]-a[x][xx]>a[y][2]-a[y][yy]) return true;
    else return false;
}
bool cmp3(int x,int y){
    int xx,yy;
    if(a[x][2]>a[x][1]) xx=2;
    else xx=1;
    if(a[y][2]>a[y][1]) yy=2;
    else yy=1;
    if(a[x][3]-a[x][xx]>a[y][3]-a[y][yy]) return true;
    else return false;
}
void abc(){
    int n,fx=0,fy=0,fz=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i][1]>>a[i][2]>>a[i][3];
        if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]){
            fx++;
            b[fx]=i;
        }
        else if(a[i][2]>a[i][3]){
            fy++;
            c[fy]=i;
        }
        else{
            fz++;
            d[fz]=i;
        }
    }
    if(fx>n/2){
        sort(b+1,b+n+1,cmp1);
        while(fx>n/2){
            int k=b[fx];
            b[fx]=0;
            fx--;
            if(a[k][2]>a[k][3]){
                fy++;
                c[fy]=k;
            }
            else{
                fz++;
                d[fz]=k;
            }
        }
    }
    else if(fy>n/2){
        sort(c+1,c+n+1,cmp2);
        while(fy>n/2){
            int k=c[fy];
            c[fy]=0;
            fy--;
            if(a[k][1]>a[k][3]){
                fx++;
                b[fx]=k;
            }
            else{
                fz++;
                d[fz]=k;
            }
        }
    }
    else if(fz>n/2){
        sort(d+1,d+n+1,cmp3);
        while(fz>n/2){
            int k=d[fz];
            d[fz]=0;
            fz--;
            if(a[k][1]>a[k][2]){
                fx++;
                c[fx]=k;
            }
            else{
                fy++;
                d[fy]=k;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=fx;i++) ans+=a[b[i]][1];
    for(int i=1;i<=fy;i++) ans+=a[c[i]][2];
    for(int i=1;i<=fz;i++) ans+=a[d[i]][3];
    cout<<ans<<'\n';
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int q;
    cin>>q;
    while(q--) abc();
    return 0;
}
