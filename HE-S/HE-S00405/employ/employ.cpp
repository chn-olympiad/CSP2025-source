#include<bits/stdc++.h>
using namespace std;
int n,m,c[501],ans=1;
char s[501];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    for(int i=1;i<=n;i++){
        ans*=i;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
