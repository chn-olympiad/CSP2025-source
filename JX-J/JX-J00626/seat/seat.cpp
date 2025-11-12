#include<bits/stdc++.h>
using namespace std;
int maopao(const int &a,const int &b){
    if(a>b) return 1;
    if(a==b) return 0;
    if(a<b) return 0;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","W",stdout);
    int n,m,s;
    cin>>n>>m;
    int a[n*m+5];
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    s=a[0];
    if(n==1){
        sort(a,a+10,maopao);
        for(int i=0;i<sizeof(a);i++){
            if(a[i]==s){
                cout<<i+1<<n;
            }
        }
    }
    if(m==1){
        sort(a,a+10,maopao);
        for(int i=0;i<sizeof(a);i++){
            if(a[i]==s){
                cout<<m<<i+1;
            }
        }
    }
    sort(a,a+10,maopao);
    for(int i=0;i<sizeof(a);i++){
        if(a[i]==s){
            if((i+1)/n%2!=0)
                cout<<(i+1)/n<<(i+1)%n;
            }else{
                cout<<(i+1)/n<<n+1-(i+1)%n;
            }
        }
    return 0;
}
