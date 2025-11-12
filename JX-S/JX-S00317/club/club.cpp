#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,m,a[N][5],ans=-1;
struct no{
    int s1,s2,s3,ss;
}aa[N];
bool cmp(no x,no y){
    return x.ss>y.ss;
}
void dfs(int x,int sum,int f1,int f2,int f3){
    if(x==n+1){
        ans=max(sum,ans);
        return;
    }
    if(f1<m)dfs(x+1,sum+a[x][1],f1+1,f2,f3);
    if(f2<m)dfs(x+1,sum+a[x][2],f1,f2+1,f3);
    if(f3<m)dfs(x+1,sum+a[x][3],f1,f2,f3+1);
}
void dfss(int x,int sum,int f1,int f2){
    if(x==n+1){
        ans=max(sum,ans);
        return;
    }
    if(f1<m)dfss(x+1,sum+a[x][1],f1+1,f2);
    if(f2<m)dfss(x+1,sum+a[x][2],f1,f2+1);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        ans=-1;
        m=n/2;
        int t1=0,t2=0,t3=0,f1=0,f2=0,f3=0,q1=1,q2=1,q3=1;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][1]!=0)q1=0;
            if(a[i][2]!=0)q2=0;
            if(a[i][3]!=0)q3=0;
            int t=max(a[i][1],max(a[i][2],a[i][3]));
            aa[i]={a[i][1],a[i][2],a[i][3],t};
            if(t==a[i][1])t1++,f1+=t;
            else if(t==a[i][2])t2++,f2+=t;
            else if(t==a[i][3])t3++,f3+=t;
        }
        //cout<<t1<<" "<<t2<<" "<<t3<<"\n";
        if(t1<=m&&t2<=m&&t3<=m){
            cout<<f1+f2+f3<<"\n";
            continue;
        }
        if((q1&&q2&&!q3)||(!q1&&q2&&q3)||(q1&&!q2&&q3)){
            sort(aa+1,aa+n+1,cmp);
            ans=0;
            for(int i=1;i<=m;i++){
                ans+=aa[i].ss;
            }
            cout<<ans<<"\n";
            continue;
        }
        if(t3==0){
            dfss(1,0,0,0);
            cout<<ans<<"\n";
            continue;
        }
        dfs(1,0,0,0,0);
        cout<<ans<<"\n";
    }
    return 0;
}