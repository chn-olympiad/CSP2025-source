#include<bits/stdc++.h>
using namespace std;

int a[5005];long long b[5005];

const int mod = 998244353;

long long ans = 0;

void dfs(vector < int > & v,int qu, int cha , int mu , int num){
    if(qu >= v.size())return;
    if(cha > v[qu]){
    int t = b[qu-mu] + 1;
    if(num == 1)ans = (ans + t - 1)%mod;
    else ans = (ans + t)%mod;
        return;
    }
    if(mu >= qu)return;
    dfs(v,qu,cha + v[mu],mu + 1,num + 1);
    dfs(v,qu,cha,mu + 1,num);
}

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n ;
    cin >> n;
    vector < int > v(n+1);
    v[0] = 0;
    for(int i = 1;i <= n;i ++)
        scanf("%d",&v[i]);
    sort(v.begin(),v.end());
    for(int i = 1;i <= n;i ++)
    {
        a[i] = a[i-1] + i;
        b[i] = b[i-1] + a[i];
    }
    for(int i = 3;i <= n;i ++)
    {
        dfs(v,i,0,1,0);
    }
    cout << ans;
    return 0;
}
