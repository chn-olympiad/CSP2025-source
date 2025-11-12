#include<bits/stdc++.h>
using namespace std;
struct node{
    int x,y,z,maxn;
    char c;
};
int t,n,xx,yy,zz;
double pjz;
struct node a[200005];
bool vis[200005];
bool cmp1(node a,node b){
    return a.maxn>b.maxn;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){

        memset(a,0,sizeof(a));
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
            a[i].maxn=max(a[i].x,max(a[i].y,a[i].z));
            if(a[i].x==a[i].maxn){
                a[i].c='x';
            }else if(a[i].y==a[i].maxn){
                a[i].c='y';
            }else{
                a[i].c='z';
            }
        }
        sort(a+1,a+n+1,cmp1);
        int sum=0;
        for(int i=1;i<=n;i++){
            if(a[i].c=='x'){
                if(xx<n/2){
                    xx++;
                    sum+=a[i].x;
                }
            }else if(a[i].c=='y'){
                if(yy<n/2){
                    yy++;
                    sum+=a[i].y;
                }

            }else if(a[i].c=='z'){
                if(zz<n/2){
                    zz++;
                    sum+=a[i].z;
                }
            }

        }
        cout<<sum<<'\n';
    }
    return 0;
}
