#include<bits/stdc++.h>
#include<bits/stl_algo.h>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define ll long long
#define ull unsigned long long
int n,m,a[105],r,ans[25];
bool cmp(int x,int y){return x>y;}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    int N=n*m;
    for (int i=1;i<=N;i++)cin>>a[i];
    int p=a[1];
    sort(a+1,a+N+1);
    reverse(a+1,a+N+1);
    for (int i=1;i<=N;i++){
        if (a[i]==p){
            r=i;
            break;
        }
    }
    for (int i=1;i<=n;i++)ans[i]=i;
    for (int i=n+1;i<=2*n;i++)ans[i]=2*n-i+1;
    int mod=2*n;
    cout<<(r-1)/m+1<<" "<<ans[r%mod]<<endl;
    return 0;
}
