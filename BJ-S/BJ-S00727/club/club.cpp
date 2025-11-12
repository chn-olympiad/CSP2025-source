#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;

int a[N][4],a1[N],n,ans=INT_MIN;

//dfs30(现在递归的个数，选择部门1，2，3的个数，满意度)
void dfs30(int cur,int cnt1,int cnt2,int cnt3,int good) {
    if(cnt1>n/2||cnt2>n/2||cnt3>n/2) return ;
    if(cur>n) {
        ans=max(ans,good);
        return ;
    }
    for(int i=1;i<=3;i++) {
        if(i==1)        dfs30(cur+1,cnt1+1,cnt2,cnt3,good+a[cur][1]);
        else if(i==2)   dfs30(cur+1,cnt1,cnt2+1,cnt3,good+a[cur][2]);
        else            dfs30(cur+1,cnt1,cnt2,cnt3+1,good+a[cur][3]);
    }
}

void solve30() {
    ans=INT_MIN;
    dfs30(1,0,0,0,0);
    cout<<ans<<endl;
}

bool check_A() {
    for(int i=1;i<=n;i++) 
        if(a[i][2]!=0||a[i][3]!=0)  return false;
    return true;
}

void solve_A() {
    for(int i=1;i<=n;i++)       a1[i]=a[i][1];
    sort(a1+1,a1+n+1);
    int res=0;
    for(int i=1;i<=n/2;i++)     res+=a1[i];
    cout<<res<<endl;
}

bool check_B() {
    for(int i=1;i<=n;i++) 
        if(a[i][3]!=0)  return false;
    return true;
}

struct node {
    int id,val;
    bool vis;
} bm1[N],bm2[N] ;

int cnt1[N],cnt2[N];

bool cmp(node x,node y) {
    if(x.val!=y.val)   return x.val>y.val;
    return x.id<y.id;
}

void solve_B() {
    for(int i=1;i<=n;i++) {
        bm1[i].val=a[i][1];
        bm2[i].val=a[i][2];
        bm1[i].id=bm2[i].id=i;
    }
    sort(bm1+1,bm1+n+1,cmp);
    sort(bm2+1,bm2+n+1,cmp);
    for(int i=1;i<=n;i++)   cnt1[bm1[i].id]=cnt2[bm2[i].id]=i;
    int res=0;
    for(int i=1;i<=n;i++) 
        if(!bm1[i].vis) {
            if(bm1[i].val>=bm2[ cnt2[ bm1[i].id ] ].val)    res+=bm1[i].val;
            else                                            res+=bm2[i].val;
            bm1[i].vis=bm2[ cnt2[ bm1[i].id ] ].vis=true;
        }
    cout<<res<<endl;
}

int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    int t;
    cin>>t;
    while(t--) {
        memset(a,0,sizeof(a));
        cin>>n;
        for(int i=1;i<=n;i++) 
            for(int j=1;j<=3;j++) 
                cin>>a[i][j];

        if(n<=30)               solve30();
        else if(check_A())      solve_A();
        else if(check_B())      solve_B();
    }

    return 0;
}
