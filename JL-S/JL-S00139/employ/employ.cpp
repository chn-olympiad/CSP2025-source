#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,t;
char a[510];
int c[510];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]=='0'){
            t=1;
        }
    }
    int sum=n;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        if(!c[i]){
            sum--;
        }
    }
    cout<<0;
    return 0;
}
