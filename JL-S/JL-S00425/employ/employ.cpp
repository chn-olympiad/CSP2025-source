#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
long long n,m,c[505],ljj=1,mem;
string a;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>a;
    for(int i=1;i<=n;i++)cin>>c[i];
    for(int i=1;i<=a.size();i++){
        if(n==0||mem==m)break;
        ljj*=n;
        mem++;
        n--;
        ljj=ljj%N;
    }
    cout<<ljj;
    return 0;
}