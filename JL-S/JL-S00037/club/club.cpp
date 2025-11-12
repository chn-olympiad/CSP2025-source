#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,ans,maxn;
int a[N][5],s[5],b[N];
void dfs(int x,int y){
    if(x==n+1){
        maxn=max(maxn,y);
        return ;
    }
    for(int i=1;i<=3;i++){
        if(s[i]<ans){
            s[i]++;
            dfs(x+1,y+a[x][i]);
            s[i]--;
        }
    }
    return ;
}
void ddfs(int x,int y){
    if(x==n+1){
        maxn=max(maxn,y);
        return ;
    }
    for(int i=1;i<=2;i++){
        if(s[i]<ans){
            s[i]++;
            dfs(x+1,y+a[x][i]);
            s[i]--;
        }
    }
    return ;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        ans=n/2,maxn=-1;
        int A=1,B=1;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][3]!=0||a[i][1]==0)
                B=0,A=0;
            if(a[i][2]!=0)
                A=0;
            b[i]=a[i][1];
        }
        if(A){
            maxn=0;
            sort(b+1,b+1+n);
            for(int i=n;i>n/2;i--)
                maxn+=b[i];
        }
        else if(B){
            ddfs(1,0);
        }
        else
            dfs(1,0);
        cout<<maxn<<endl;
    }
    return 0;
}
