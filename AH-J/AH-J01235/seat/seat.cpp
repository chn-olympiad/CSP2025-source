#include<bits/stdc++.h>
using namespace std;
int n,m,ans,s,c,l;
int a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    int s1=s,p=0;
    for(int i=2;i<=n*m;i++){
        cin>>s;
        if(s>s1) p++;
    }
    c=p/n;
    if(c%2==0) l=p%n;
    else l=(n-1)-(p%n);
    cout<<c+1<<" "<<l+1;
    return 0;
}
