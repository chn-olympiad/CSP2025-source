#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],p[505],ans;
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m>>s; s=" "+s;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) p[i]=i;
    do{
        int x=0,y=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='0'||y>=a[p[i]]) y++;
            else x++;
        }
        if(x>=m) ans++;
    }while(next_permutation(p+1,p+n+1));
    cout<<ans;
    return 0;
}