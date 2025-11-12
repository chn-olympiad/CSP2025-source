#include<bits/stdc++.h>
using namespace std;
int n,m,o=1,p=1,c,k;
bool ud;
int l[1145];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    k=m*n;
    for(int i=1;i<=k;i++)cin>>l[i];
    c=l[1];
    sort(l+1,l+k+1);
    ud=true;
    for(int i=k;i>=1;i--){
        if(l[i]==c)cout<<p<<" "<<o;
        if(o==m&&ud){
            ud=false;
            p+=1;
            continue;
        }
        else if(o==1&&!ud){
            ud=true;
            p+=1;
            continue;
        }
        if(ud)o+=1;
        else o-=1;
    }
    return 0;
}
