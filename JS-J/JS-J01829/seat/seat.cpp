#include<bits/stdc++.h>
using namespace std;
int n,m,r,a[105],und=0;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>r;
    for(int i=1;i<n*m;i++){
        int x;
        cin>>x;
        if(x>r)und++;
    }
    int n1=0,m1=0;
    m1=und/n+1;
    int xn=und+1-n*(m1-1);
    if(m1%2==0)n1=n-xn+1;
    else n1=xn;
    cout<<m1<<' '<<n1;
    return 0;
}
