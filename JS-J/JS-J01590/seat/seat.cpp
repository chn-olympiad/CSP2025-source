#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,x;
    cin>>n>>m;
    cin>>a[0];
    x=a[0];
    for(int i=1;i<n*m;i++){
        cin>>a[i];
    }
    sort(a,a+n*m,greater<int>());
    int j=0;
    while(a[j]!=x){
        j++;
    }
    int op=j/n+1;
    j=j%n;
    if(op%2==1) cout<<op<<' '<<j+1;
    else cout<<op<<' '<<n-j;
    return 0;
}
