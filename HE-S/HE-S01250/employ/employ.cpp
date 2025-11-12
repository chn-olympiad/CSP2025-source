#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[1001],dp[10001][10001];

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i = 0;i<n;i++){
        cin>>c[i];
    }
    sort(c,c+n);
}
