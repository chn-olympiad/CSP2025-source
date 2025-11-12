#include<bits/stdc++.h>
using namespace std;
int a[200];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,x,s;
    cin>>n>>m;
    int l=n*m;
    for(int i=0;i<l;i++){
        cin>>a[i];
    }
    x=a[0];
    sort(a,a+l);
    for(int i=l-1;i>=0;i--){
        if(a[i]==x){
            s=l-i;
            break;
        }
    }
    int x1=2*(s/(2*n))+1;
    int y=s%(2*n);
    if(y==0) y=(2*n);
    if(y>n){
        x1++;
        y=(2*n)-y+1;
    }
    cout<<x1<<" "<<y;
    return 0;
}
