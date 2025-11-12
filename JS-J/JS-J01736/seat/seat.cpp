#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    int n,m,num,a[100],rk=0;
    cin>>n>>m;
    num=n*m;
    for(int i=0;i<num;i++){
        cin>>a[i];
        if(a[i]>a[0]) rk++;
    }
    int r=rk/n+1;
    cout<<r<<' ';
    int c=(r&1)?((rk%n)+1):(n-(rk%n));
    cout<<c;
    return 0;
}
