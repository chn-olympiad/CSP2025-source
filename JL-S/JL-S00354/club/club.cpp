#include<bits/stdc++.h>
using namespace std;
struct aaa{
    int a,b,c;
}s[10000];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>s[i].a>>s[i].b>>s[i].c;

        }
    }
    return 0;
}

