#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,all,res;
char s[510];
int main(){

    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    for(int i=1;i<=n;i++){
        cin>>s[i];
        if(s[i]==0){
            cnt++;
        }
    }
    all=n-cnt;
    for(int i=1;i<=all;i++){
        res*=i;
    }
    cout<<res;

    return 0;
}
