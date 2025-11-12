#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t;
int n;
int a[N][4];
int finans;
void dfs(int x,int first,int second,int third,int ans){
    finans=max(finans,ans);
    if(x>n){
        return;
    }
    if( (a[x][1]>=a[x][2] || a[x][1]>=a[x][3]) && first<n/2){
        dfs(x+1,first+1,second,third,ans+a[x][1]);
    }
    if( (a[x][2]>=a[x][1] || a[x][2]>=a[x][3]) && second<n/2){
        dfs(x+1,first,second+1,third,ans+a[x][2]);
    }
    if( (a[x][3]>=a[x][2] || a[x][3]>=a[x][1]) && third<n/2){
        dfs(x+1,first,second,third+1,ans+a[x][3]);
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;

    while(t--){
        int first,second,third;
        memset(a,0,sizeof(a));
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        finans=0;
        dfs(1,0,0,0,0);
        cout<<finans<<endl;
    }

}
