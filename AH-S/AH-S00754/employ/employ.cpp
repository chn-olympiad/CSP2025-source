#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,s[505],c[505],p[505],ans;
bool check(){
    ll qi=0;
    for(int i=1;i<=n;i++){
        if(s[i]==0) qi++;
        else if(qi>=c[p[i]]) qi++;
    }
    if(n-qi>=m) return 1;
    else return 0;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
            char x;
    cin>>x;
    s[i]=x-'0';
        }
    for(int i=1;i<=n;i++)
        cin>>c[i];
    for(int i=1;i<=n;i++)
        p[i]=i;
    do{
        ans+=check();
    }while(next_permutation(p+1,p+n+1));
    cout<<ans;
    return 0;
}
