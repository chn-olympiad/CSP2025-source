#include<iostream>
#include<algorithm>
using namespace std;
int a[100];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=0;i<n*m;i++)cin>>a[i];
    int f=a[0];
    sort(a,a+n*m);
    int i=0;
    for(;i<n*m;i++)if(a[i]==f)break;
    int ind=n*m-i-1;
    cout<<ind/n+1<<' ';
    if(ind/n%2)cout<<m-(ind%n);
    else cout<<ind%n+1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}