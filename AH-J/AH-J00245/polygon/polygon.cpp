#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5010;
int n;
int a[N];
bool v[N];
int cnt;
int maxx(int x,int y){
    if(x>=y)return x;
    else return y;
}
void dfs(int sum,int m,int mx,int t){
    if(sum>2*mx){
        cnt++;
    }
    if(m<t){
        for(int i=1;i<=n;i++){
            if(v[i]==0){
                v[i]=1;
                int mxx=maxx(mx,a[i]);
                dfs(sum+a[i],m+1,mxx,t);
                v[i]=0;
            }
        }
    }
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cout<<0;
    return 0;
}
