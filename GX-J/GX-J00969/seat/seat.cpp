#include<iostream>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,k;
    cin>>n>>m;
    int a[n*m],b[n*m],sy=0;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    int maxn=-1;
    for(int i=0;i<n*m;i++){
        if(a[i]>maxn){
            maxn=a[i];
        }
    }
    for(int i=maxn;i>=0;i--){
        for(int y=0;y<m*n;y++){
            if(i==a[y]){
                if(y==0){
                    k=sy+1;
                }
                b[sy]=i;
                sy++;
            }
        }
    }
    if(k%n==0){
        cout<<k/n<<" ";
        if((k/n)%2==1){
            cout<<n;
        }
        else{
            cout<<1;
        }
    }
    else{
        cout<<k/n+1<<" ";
        if((k/n+1)%2==1){
            cout<<k%n;
        }
        else{
            cout<<n-k%n+1;
        }
    }
    return 0;
}
