#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,num;
    cin>>n>>m;
    int a[100];
    for(int i=0;i<=m*n;i++){
        cin>>a[i];
        num=a[0];
        if(a[0]<a[i]){
            cout<<n<<" "<<m;
            break;
        }
        else{
            cout<<n-1<<" "<<m;
            break;
        }

        if(a[0]>a[i]){
            cout<<"1 1";
            break;
        }
         else{
            cout<<n<<" "<<m-1;
            break;
        }
    return 0;
    }

