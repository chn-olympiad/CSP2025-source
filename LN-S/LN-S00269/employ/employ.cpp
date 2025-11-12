#include<bits/stdc++.h>
using namespace std;
long long n,m,c[505],ans,sum,num,p[505];
char s[505];
stack<int> pre;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    for (int i=1;i<=n;i++){
        cin>>s[i];
    }
    for (int i=1;i<=n;i++){
        cin>>c[i];
    }
    for (int i=1;i<=n;i++){
        pre.push(p[i]);
        if (c[i]<sum){
            pre.pop();
        }
        if (s[i]=='0'){
            pre.pop();
            sum++;
        }
        else{
            num++;
        }
        if (sum==num){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
