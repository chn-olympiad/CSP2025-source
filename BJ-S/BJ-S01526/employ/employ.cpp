#include<bits/stdc++.h>
using namespace std;
const long long P=998244353LL;
long long fact(int n){
    if(n<=1)return 1LL;
    else return n*(fact(n-1))%P;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,qqq;
    cin>>n>>m;
    string s;
    cin>>s;
    int c[505];
    for(int i=1;i<=n;i++){
        cin>>c[i];
        if(c[i]>0)qqq++;
    }
    if(qqq<m){
        cout<<0;
        return 0;
    }
    cout<<fact(n);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
