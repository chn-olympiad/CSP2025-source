#include<iostream>
#include<algorithm>
using namespace std;

int n,m,k;
int a[110];

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>k;
    a[1]=k;
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
    }
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++){
        if(a[i]==k){
            k=n*m-i+1;
        }
    }
    if((k/n)%2==0){
        cout<<(k/n)+1-(k%n==0)<<" "<<(k%n);
    }
    else{
        cout<<(k/n)+1-(k%n==0)<<" "<<(n-k%n+1-(k%n==0));
    }

    return 0;
}

