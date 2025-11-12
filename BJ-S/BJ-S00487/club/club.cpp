#include<bits/stdc++.h>
using namespace std;
int sum,n;
struct node{
    int x,y,v;
}a[100005];
bool fl[100005];
int num[4];
bool cmp(node kk,node kk2){
    return kk.v>kk2.v;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int k=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[++k].v;
                a[k].x=i,a[k].y=j;
            }
        }
        sort(a+1,a+3*n+1,cmp);
        for(int i=1;i<=3*n;i++){
            int vv=a[i].v,xx=a[i].x,yy=a[i].y;
            if(num[yy]+1<=n/2&&!fl[xx]){
                sum+=vv;
                fl[xx]=1;
                num[yy]++;
            }
        }
        cout<<sum<<endl;
        sum=0;
        memset(fl,0,sizeof(fl));
        memset(num,0,sizeof(num));
    }
    /*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
    */
    return 0;
}