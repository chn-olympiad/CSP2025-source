#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
int a[N][10],b[N];
struct awa{
    int a,b,c,i;
}c[N],num[N];
int club[N];

void cle(int n){
    for(int i=1;i<=n;i++){
        b[i]=0;
        c[i].a=0;c[i].b=0;c[i].c=0;c[i].i=0;
        num[i].a=0;num[i].b=0;num[i].c=0;num[i].i=0;
        club[i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++)a[i][j]=0;
    }
}


bool check1(int n){
    for(int i=1;i<=n;i++)if(a[i][2])return false;
    return true;
}

bool check2(int n){
    for(int i=1;i<=n;i++)if(a[i][3])return false;
    return true;
}

bool cmp1(awa x,awa y){return x.a>y.a;}
bool cmp2(awa x,awa y){return x.b>y.b;}
bool cmp3(awa x,awa y){return x.c>y.c;}

void solve(int n){
    for(int i=1;i<=n;i++){
        if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])club[1]++,num[i].i=i,num[i].a=a[i][1];
        else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])club[2]++,num[i].i=i,num[i].b=a[i][2];
        else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2])club[3]++,num[i].i=i,num[i].c=a[i][3];
    }
    if(club[1]<=n/2&&club[2]<=n/2&&club[3]<=n/2){
        int ans=0;
        for(int i=1;i<=n;i++)ans+=max(a[i][1],max(a[i][2],a[i][3]));
        cout<<ans<<"\n";
        return;
    }
    else if(club[1]>n/2){
        sort(num+1,num+1+club[1],cmp1);
        int ans=0;
        for(int i=1;i<=n/2;i++)ans+=num[i].a;
        for(int i=1;i<=club[2];i++)ans+=num[i].b;
        for(int i=1;i<=club[3];i++)ans+=num[i].c;
        for(int i=n/2+1;i<=club[1];i++)ans+=max(num[num[i].i].b,num[num[i].i].c);
        cout<<ans<<"\n";
    }
    else if(club[2]>n/2){
        sort(num+1,num+1+club[2],cmp2);
        int ans=0;
        for(int i=1;i<=n/2;i++)ans+=num[i].b;
        for(int i=1;i<=club[1];i++)ans+=num[i].a;
        for(int i=1;i<=club[3];i++)ans+=num[i].c;
        for(int i=n/2+1;i<=club[2];i++)ans+=max(num[num[i].i].a,num[num[i].i].c);
        cout<<ans<<"\n";
    }
    else if(club[3]>n/2){
        sort(num+1,num+1+club[3],cmp3);
        int ans=0;
        for(int i=1;i<=n/2;i++)ans+=num[i].c;
        for(int i=1;i<=club[1];i++)ans+=num[i].a;
        for(int i=1;i<=club[2];i++)ans+=num[i].b;
        for(int i=n/2+1;i<=club[3];i++)ans+=max(num[num[i].i].a,num[num[i].i].b);
        cout<<ans<<"\n";
    }
}


bool cmpA(int x,int y){return x>y;}
void solveA(int n){
    for(int i=1;i<=n;i++)b[i]=a[i][1];
    sort(b+1,b+1+n,cmpA);
    int ans=0;
    for(int i=1;i<=n/2;i++)ans+=b[i];
    cout<<ans<<"\n";
}


int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ll QwQ;
    cin>>QwQ;
    while(QwQ-->0){
        ll n;
        cin>>n;
        cle(n);
        for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3];
        if(check1(n)&&check2(n))solveA(n);
        else solve(n);
    }
}

//QwQ
//18:00 le wei shen me yang li dou bu guo ,wo ju ran guo le zui hou yi ge da yang li
//hai shi bu neng ma
