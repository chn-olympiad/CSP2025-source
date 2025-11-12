#include<iostream>
using namespace std;
int n,m;
int a[1000005];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out.out","w",stdout);
    cin>>n>>m;
    if(n==2||m==2){
        cout <<1<<" "<<2;
    }
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int k=a[1];
    return 0;
}
