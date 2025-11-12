#include<bits/stdc++.h>
using namespace std;
int n,m,p,c[505],sum=1,ans;
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    sort(c+1,c+n+1);
    for(int i=2;i<=n;i++){
        if(c[i]!=c[i-1]&&sum!=1){
            ans+=sum;
            sum=1;
        }
    }
    cout<<ans;
    return 0;
}
