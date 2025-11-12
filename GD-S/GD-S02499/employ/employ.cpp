#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int a[maxn][10];
int vis[4],n,vis1[maxn],res;

int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
	int n;cin>>n;
	cout<<pow(2,n)-4;
    return 0;
}
