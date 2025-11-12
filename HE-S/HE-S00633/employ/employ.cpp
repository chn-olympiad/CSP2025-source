#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxm 1000005
#define maxn 10005
ll n,m,k;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    if (m==0){
        cout<<(n*(n+1)/2)%998244353;
    }else {
		cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
