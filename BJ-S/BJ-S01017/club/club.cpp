#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int s[5];
int a[N],b[N],c[N],z[N];
int n,cnt,Max;
struct op{
    int x;
    int y;
}r[N];
void dfs(int x){
    if(x==n+1){
        Max=max(Max,cnt);
        return;
    }
    if(s[1]<n/2){
        s[1]++;
        z[x]=1;
        cnt+=a[x];
        dfs(x+1);
        s[1]--;
        z[x]=0;
        cnt-=a[x];
    }
    if(s[2]<n/2){
        s[2]++;
        z[x]=2;
        cnt+=b[x];
        dfs(x+1);
        s[2]--;
        z[x]=0;
        cnt-=b[x];
    }
    if(s[3]<n/2){
        s[3]++;
        z[x]=3;
        cnt+=c[x];
        dfs(x+1);
        s[3]--;
        z[x]=0;
        cnt-=c[x];
    }
}
bool cmp(op a,op b){
    return a.x<b.x;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
        }
        if(n<=10){
            cnt=Max=0;
            dfs(1);
            cout<<Max<<endl;
        }
        else if(b[1]==0&&b[2]==0&&b[3]==0&&c[1]==0&&c[2]==0&&c[3]==0){
            sort(a+1,a+1+n);
            cnt=0;
            for(int i=1;i<=n/2;i++){
                cnt+=a[i];
            }
            cout<<cnt<<endl;
        }
        else if(c[1]==0&&c[2]==0&&c[3]==0){
            cnt=0;
            for(int i=1;i<=n;i++)r[i].x=a[i]-b[i],r[i].y=i;
            sort(r+1,r+1+n,cmp);
            for(int i=1;i<=n/2;i++)cnt+=a[r[i].y];
            for(int i=n/2+1;i<=n;i++)cnt+=b[r[i].y];
            cout<<cnt<<endl;
        }
    }

    return 0;
}
