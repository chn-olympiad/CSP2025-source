#include<bits/stdc++.h>
using namespace std;
#define ll long long
void sovle(){
    int n,m,a1;
    int a[110];
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    a1=a[0];
    sort(a,a+n*m);
    for(int i=0;i<n*m;i++){
        if(a[i]==a1){
            a1=n*m-i;
            break;
        }
    }
    if(((a1-1)/n+1)%2==0){
        cout<<(a1-1)/n+1<<" ";
        if(a1%n==0){
            cout<<1;
        }
        else{
            cout<<n-a1%n+1;
        }
    }
    else{
        cout<<(a1-1)/n+1<<" ";
        if(a1%n==0){
            cout<<n;
        }
        else{
            cout<<a1%n;
        }
    }
}
int main(){
    ios::sync_with_stdio();
    cin.tie();
    cout.tie();
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int t=1;
    while(t--){
        sovle();
    }
    return 0;
}
