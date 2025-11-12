#include <bits/stdc++.h>
using namespace std;
//define int long long
int n,m,z,a[100];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int i,j;
    cin>>n>>m;
    for(i=0;i<n*m;i++) cin>>a[i];
    z=a[0];
    sort(a,a+n*m,cmp);
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(a[i*m+j]==z){
                cout<<i+1<<' ';
                i&1? cout<<m-j: cout<<j+1;
                cout<<endl;
                break;
            }
        }
    }
    return 0;
}
