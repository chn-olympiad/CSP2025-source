#include<bits/stdc++.h>
using namespace std;
const int N=15;
int n,m,a[N*N];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int k=n*m;
    cin>>a[1];
    int num=1;
    for(int i=2;i<=k;i++){
        cin>>a[i];
        if(a[i]>a[1])num++;
    }
    //for(;num<=k;num++){
    if(num%n==0){
        int kk=num/n;
        if(kk%2==1){
            cout<<num/n<<" "<<n<<endl;
        }
        else{
            cout<<num/n<<" "<<1<<endl;
        }
    }
    else{
        int kk=num/n+1;
        if(kk%2==1){
            cout<<kk<<" "<<num%n<<endl;
        }
        else{
            cout<<kk<<" "<<(n-num%n+1)<<endl;
        }
    }
    return 0;
}
