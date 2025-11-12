#include <bits/stdc++.h>
using namespace std;
int n,m,ma,plan;
int c[500];

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        c[a]++;
        ma = max(ma,a);
    }
    plan = 1;
    for(int i=0;i<=ma;i++){
        if(c[i]!=0){
            plan*=c[i];
            plan = (plan+998244353)%998244353;
        }
    }
    cout<<plan;
}