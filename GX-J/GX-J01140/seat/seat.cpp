#include<iostream>
using namespace std;
int l[101]={0},s[101]={0};int a,n,m,r,so=0;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;cin>>r;
    for(int k=1;k<n*m;k++){
        cin>>a;
        if(a>r) so++;
    }
    int mr=so/n+1,nr=so%n+1;
    if(mr%2==0) nr=n-nr+1;
    cout<<mr<<' '<<nr;
    return 0;
}
