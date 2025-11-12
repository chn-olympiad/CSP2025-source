#include <iostream>
#include <algorithm>
#define ll long long
#define mod 998244353
using namespace std;
int n,m;
int ok[1004];
int man[1005];
int day[1005];
ll ans=0;
ll jc(int y){
    int as=1;
    for(int i=2;i<=y;i++){
        as*=i;
        as=as%mod;
    }
    return as;
}
void dfs (int x,int k,int c){//c:lu,k:ban
    if(x>n || c>=m){
        if(c<m){
            return ;
        }
        ans+=jc(n-x+1);
        cout<<ans<<endl;
        return ;
    }
    for(int i=1;i<=n;i++){
        int dc=0;
        int dk=0;
        if(ok[i])continue;
        if(c<man[i]){
            if(day[x]){
                dc++;
            }

            else dk++;
        }
        else dk++;
        //cout<<"d"<<x<<" "<<k<<" "<<c<<endl;
        ok[i]=1;
        dfs(x+1,k+dk,c+dc);
        ok[i]=0;
    }
}

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    int ones=0;
    string tt;
    cin>>tt;
    for(int i=0;i<n;i++){
        day[i+1]=tt[i]-'0';
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&man[i]);
    }
    dfs(1,0,0);
    cout<<ans;
    return 0;
}
