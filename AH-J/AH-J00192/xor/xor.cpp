#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool cmp(int a,int b){
    return a>b;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[1000000];
    cin>>n>>m;
    if(m==0){
       for(int i=0;i<n;i++){
           cin>>a[i];
       }
       sort(a,a+n,cmp);
       cout<<a[0];
    }
    return 0;
}
