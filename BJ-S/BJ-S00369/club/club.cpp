#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
int b[N][4],n,dp[5001][5001];
struct node{
    int a,aid;
    int b,bid;
    int c,cid;
    int id;
}a[N];
struct n2{
    int c,id;
}d[4];
bool cmp(node x,node y){
    return x.a==y.a ? (x.b==y.b ? (x.c>y.c) : x.b>y.b) : x.a>y.a;
    //return x.a+y.a==x.b+y.b ? x.b+y.b>x.c+y.c :x.a+y.a>x.b+y.b;
}
bool cmp2(n2 x,n2 y){
    return x.c>y.c;
}
int ji[4],ans=0,ma=0;
int main(){
    //freopen!!!!
    //freopen("club.in","r",stdin);
    //freopen("club.out","w",stdout);
    int _,f=0,f2=0;
    cin>>_;
    while(_--){
        ma=0;
        f=1,f2=1;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>b[i][1]>>b[i][2]>>b[i][3];
            if(b[i][2]!=0||b[i][3]!=0)f=0;
            if(b[i][3]!=0)f2=0;
            a[i].id=i,a[i].a=b[i][1],a[i].b=b[i][2],a[i].c=b[i][3];
            a[i].aid=1,a[i].bid=1,a[i].cid=1;
            if(a[i].a>a[i].b){
                swap(a[i].a,a[i].b);
                swap(a[i].aid,a[i].bid);
            }
            if(a[i].b>a[i].c){
                swap(a[i].b,a[i].c);
                swap(a[i].bid,a[i].cid);
            }
        }
        if(n==2){
            cout<<max({b[1][1]+b[2][1],b[1][1]+b[2][2],b[1][1]+b[2][3],
                      b[1][2]+b[2][1],b[1][2]+b[2][2],b[1][2]+b[2][3],
                      b[1][3]+b[2][1],b[1][3]+b[2][2],b[1][3]+b[2][3]})<<"\n";
        }
        if(f){
            int bb[100001];
            for(int i=1;i<=n;i++){
                bb[i]=b[i][1];
            }
            sort(bb+1,bb+1+n,greater<int>());
            for(int i=1;i<=(n>>1);i++){
                ans+=bb[i];
            }
            cout<<ans<<"\n";
            continue;
        }
        sort(a+1,a+1+n,cmp);
        /*
        for(int i=1;i<=n;i++)
        {
            cout<<a[i].id<<" \n";
        }
        cout<<"\n";*/


        for(int i=1;i<=n;i++){
            //cout<<"\nnow i="<<i<<",ans="<<ans<<"\n";
            d[1].c=b[a[i].id][1];
            d[2].c=b[a[i].id][2];
            d[3].c=b[a[i].id][3];
            d[1].id=1;
            d[2].id=2;
            d[3].id=3;
            sort(d+1,d+1+3,cmp2);
            for(int j=1;j<=3;j++){
                //cout<<ji[d[j].id]<<" "<<d[j].id<<" "<<d[j].c<<"\n";
                if(ji[d[j].id]<(n/2)){
                    ans+=d[j].c;
                    ji[d[j].id]++;
                    break;
                }
            }
            //cout<<"with each for:"<<ji[1]<<","<<ji[2]<<","<<ji[3]<<"\n";
        }
        cout<<ans<<"\n";
        ji[1]=0,ji[2]=0,ji[3]=0;
        ans=0;
    }
    return 0;
}
