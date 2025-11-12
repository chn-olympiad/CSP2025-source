#include<bits/stdc++.h>
using namespace std;
void read(int &k){
    int f=1;k=0;char c=getchar_unlocked();
    while(c<='0'||c>='9'){
        if(c=='-') f=-1;
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9'){
        k=(k<<3)+(k<<1)+c-'0';
        c=getchar_unlocked();
    }
    k*=f;
}
int n,t;
struct node{
    int a1,a2,a3,mx,smx,num,c;
}a[100005];
int main(){
    ios::sync_with_stdio(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        int ans=0,nn=n/2;
        int num[4]={0,0,0,0};
        for(int i=1;i<=n;++i){
            cin>>a[i].a1>>a[i].a2>>a[i].a3;
            a[i].mx=max(a[i].a1,max(a[i].a2,a[i].a3));
            a[i].smx=max(a[i].a1+a[i].a2,max(a[i].a3+a[i].a2,a[i].a1+a[i].a3))-a[i].mx;
            a[i].num=a[i].mx-a[i].smx;
        }
        sort(a+1,a+n+1,[](node x,node y){return x.num>y.num;});
        for(int i=1;i<=nn;++i){
            ans+=a[i].mx;
            if(a[i].mx==a[i].a1&&a[i].mx!=a[i].smx) num[1]++;
            else if(a[i].mx==a[i].a2&&a[i].mx!=a[i].smx) num[2]++;
            else if(a[i].mx==a[i].a3&&a[i].mx!=a[i].smx) num[3]++;
        }
        for(int i=nn+1;i<=n;++i){
            if(a[i].mx==a[i].a1&&num[1]>=nn) ans+=a[i].smx;
            else if(a[i].mx==a[i].a2&&num[2]>=nn) ans+=a[i].smx;
            else if(a[i].mx==a[i].a3&&num[3]>=nn) ans+=a[i].smx;
            else ans+=a[i].mx;
            if(a[i].mx==a[i].a1&&a[i].mx!=a[i].smx) num[1]++;
            else if(a[i].mx==a[i].a2&&a[i].mx!=a[i].smx) num[2]++;
            else if(a[i].mx==a[i].a3&&a[i].mx!=a[i].smx) num[3]++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}//I love CC F! Can you give me 100 pts?
