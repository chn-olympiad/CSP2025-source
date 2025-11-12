#include<bits/stdc++.h>
#define N 110
using namespace std;
int n,m,x,cnt=1,r,c;
int pe;
int a[N];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    pe=n*m;
    for(int i=1;i<=pe;i++){
        cin>>a[i];
    }
    x=a[1];
    for(int i=1;i<=pe;i++)
        if(a[i]>x){
            cnt++;
        }

    r=cnt%n;
    if(r==0)r=n;
    c=cnt/n;
    if(r!=n)c++;
    if(c%2==0)r=n-r+1;
    cout<<c<<" "<<r;
    return 0;
}
