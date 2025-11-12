#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MOD = 998244353;
int s[505],n,m,sum=0,c[505];
string x;
ll special_solve(int &u,int &v){//C(u,v)
    /*ll mid1 = 1,mid2 = 1;
    if (v >= u/2) v = u - v;
    for (int i=v;i>=v-u;i--)
        mid1 = mid1 * i % MOD;
    for (int i=2;i<=u;i++)
        mid2 = mid2 * i % MOD;*/
    ll C[505][505];//C(i,j) should be C(j,i)
    memset(C,0,sizeof(C));
    for (int i=0;i<=v;i++) C[i][0] = 1;
    //for (int i=1;i<=v;i++) C[i][0] = 1;//C(0,i)
    C[1][1] = 1;
    for (int i=2;i<=v;i++){
        for (int j=1;j<=i;j++)
            C[i][j] = (C[i-1][j]+C[i-1][j-1])%998244353;
    }
    return C[v][u];//v >= u;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>x;
    for (int i=0;i<x.size();i++)
        s[i+1] = x[i] - '0',sum += s[i+1];
    for (int i=1;i<=n;i++)
        cin>>c[i];
    if (sum == n){
        cout<<special_solve(m,n);//m<=n;
        return 0;
    }
    //fflush(stdout);
    return 0;
}
