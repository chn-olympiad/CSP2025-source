#include<bits/stdc++.h>
using namespace std;

int main(){
    /*freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);*/
    long long n,m,a[12][12],b[102],k;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>b[i];
    }
    k=b[0];
    bool f=1;
    while(f){
        f=0;
        for(int i=0;i<n*m;i++){
            if(b[i]<b[i+1]){
                swap(b[i],b[i+1]);
                f=1;
            }
        }
    }
    int js=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            a[j][i]=b[js];
            js++;
            if(a[j][i]==k){
                cout<<i+1<<" "<<j+1;
            }
        }
    }
    return 0;
}
