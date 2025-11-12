#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat1.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m,xb=0;
    cin>>n>>m;
    long long b=n*m;
    long long a[b];
    for(int i=0;i<b;i++){
        cin>>a[i];
    }
    long long r=a[0];
    sort(a,a+b);
    for(int i=0;i<b;i++){
        if(a[i]==r and a[i]<a[n]){
            cout<<"1"<<" "<<m-i;
        }
    }
     return 0;
}
