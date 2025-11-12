#include<bits/stdc++.h>//hao,nan,a
using namespace std;
int n,a[100005][4];
int bl[15],bl2[4],ansbl,mxbl;//baoli
struct node{
    int l,r;
}lB[100005];
bool cmp(node x,node y){
    if(x.l!=y.l)return x.l<y.l;
    return x.r<y.r;
}
void baoli(int i){
    ansbl=0;
    bl2[1]=bl2[2]=bl2[3]=0;
    if(i==n+1){
        for(int i=1;i<=n;i++){
            bl2[bl[i]]++;
            ansbl+=a[i][bl[i]];
            if(bl2[bl[i]]>n/2)return;
        }
        mxbl=max(mxbl,ansbl);
        return;
    }
    bl[i]=1;
    baoli(i+1);
    bl[i]=2;
    baoli(i+1);
    bl[i]=3;
    baoli(i+1);
}
void A(){
    int lA[100005];
    for(int i=1;i<=n;i++)lA[i]=a[i][1];
    sort(lA+1,lA+n+1);
    int ansA=0;
    for(int i=n;i>n/2;i--){
        ansA+=lA[i];
    }
    cout<<ansA<<endl;
}
void B(){
    int ansB=0;
    for(int i=1;i<=n;i++)lB[i].r=i,lB[i].l=a[i][1]-a[i][2];
    sort(lB+1,lB+1+n,cmp);
    for(int i=n;i>n/2;i--)ansB+=a[lB[i].r][1];
    for(int i=1;i<=n/2;i++)ansB+=a[lB[i].r][2];
    cout<<ansB<<endl;
}
void solve(){
    bool isA=true,isB=true;
    cin>>n;
    for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++)cin>>a[i][j];
            if(a[i][2]!=0||a[i][3]!=0)isA=false;
            if(a[i][3]!=0)isB=false;
    }
    if(n<=10){
        mxbl=0;
        baoli(1);
        cout<<mxbl<<endl;
        return;
    }
    if(isA){
        A();
        return;
    }
    B();
    return;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--)solve();
    return 0;
}
