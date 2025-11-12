#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int n,m,c[N],a[N],ans;
bool st[N];
string s;
void check(){
    int num1=0,num2=0;
    for(int i=1;i<=n;i++){
        if(num2<c[a[i]]&&s[i-1]=='1'){
            num1++;
        }
        if(s[i-1]=='0'){
            num2++;
        }
    }
    if(num1>=m){
        ans++;
    }
}
void f(int u){
    if(u>n){
        check();
        return;
    }
    for(int i=1;i<=n;i++){
        if(!st[i]){
            st[i]=true;
            a[u]=i;
            f(u+1);
            st[i]=false;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    f(1);
    cout<<ans%mod;
    return 0;
}
