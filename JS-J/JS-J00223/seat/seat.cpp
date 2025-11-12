#include <bits/stdc++.h>
using namespace std;
#define ll long long
int s[500];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m*n;i++){
        cin>>s[i];
    }
    int t=s[1],tot=n*m,pos=-1;
    sort(s+1,s+tot+1);
    reverse(s+1,s+tot+1);
    for(int i=1;i<=n*m;i++){
        if(s[i]==t){
            pos=i;break;
        }
    }
    int c=pos/n+1,r;
    if(pos%n==0){
        c--;
        r=(c%2==1)?n:1;
    }
    else{

        r=(c%2==1)?pos%n:n-pos%n+1;
    }
    cout<<c<<" "<<r;
    return 0;
}
