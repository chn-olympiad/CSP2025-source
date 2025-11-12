#include<bits/stdc++.h>
using namespace std;

int m,n,num[105],R,c,r;


int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>num[i];
    }
    R=num[1];
    sort(num+1,num+n*m+1);
    int l=0;
    for(int i=0;num[i]<R;i++)l++;
    l=n*m-l+1;
    c=l/n+1;
    l%=n;
    if(n%2==1)r=l;
    else if(n%2==0)r=n-l+1;
    cout<<c<<" "<<r;
    return 0;
}
