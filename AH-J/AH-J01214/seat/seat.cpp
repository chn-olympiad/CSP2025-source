#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[110],n,m,s,l=1,r=1,pos;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n*m;i++)cin>>a[i];
    s=a[1];
    sort(a+1,a+1+n*m);
    reverse(a+1,a+1+n*m);
    for(int i=1;i<=n*m;i++)if(a[i]==s)pos=i;
    for(int i=1;i<=n*m;i++){
        if(i==pos)cout<<r<<" "<<l;
        if(r%2){
            if(l==n)r++;
            else l++;
        }
        else{
            if(l==1)r++;
            else l--;
        }
    }
    return 0;
}
