#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int b,sum;
int main(){
    //freopen("seat.in","r",stdin);
    //freopen("seat.out","w",stdout);
    cin>>n>>m;
    sum=n*m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
for(int i=0;i<1;i++){
    b=a[i];
}
sort(a,a+sum);
for(int i=0;i<n*m;i++){
        cout<<a[i];
    }
    return 0;
}
