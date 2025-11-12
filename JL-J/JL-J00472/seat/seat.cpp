#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m];
    int head;
    int ans = 0;
    for(int i = 0;i<n*m;i++){
        cin>>a[i];
        if(i==0){
            head = a[i];
        }
    }
    for(int i = 0;i<n*m;i++){
        if(a[i]>head){
            ans++;
        }
    }
    int x,y;
    x = ans/n+1;
    y = ans%n+1;
    if(x%2==0){
        cout<<x<<" "<<n-y;
    }
    else{
        cout<<x<<" "<<y;
    }

}
