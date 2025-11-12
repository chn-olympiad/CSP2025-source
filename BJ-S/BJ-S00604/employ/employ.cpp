#include <bits/stdc++.h>
using namespace std;
int a[1010];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string a;
    cin>>a;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int cnt=1;
    if(m==n){
        for(int i=1;i<=n;i++){
            if(a[i]==a[i-1]){
                cnt++;
                cht%=998244353;
                cnt=(cnt+998244353)%998244353;
            }
        }
        cout<<cnt;
    }
    else{
        for(int i=1;i<=n;i++){
            if(a[i]==a[i-1]){
                cnt++;
                cht%=998244353;
                cnt=(cnt+998244353)%998244353;
            }
            cout<<cnt;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;

}
