#include<bits/stdc++.h>
using namespace std;
long long a[101],b[101]={};
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m,s=0;
    cin>>n>>m;
    for(long long i=1;i<=n*m;i++){
        cin>>a[i];
    }
    b[1]=1;
    for(long long i=2;i<=n*m;i++){
        for(long long j=n*m;j>=i;j--){
            if(a[j]>a[j-1]){
                swap(a[j],a[j-1]);
                swap(b[j],b[j-1]);
            }
        }
    }
    for(long long i=1;i<=n*m;i++){
        s++;
        if(b[i]==1){
            break;
        }
    }
    for(long long i=0;i<n;i++){
        if(i*n+1<=s and (i+1)*n>=s){
            if((i+1)%2==0){
                cout<<i+1<<" "<<m-(s-i*n)+1;
            }
            else{
                cout<<i+1<<" "<<s-i*n;
            }
        }
    }
    return 0;
}
