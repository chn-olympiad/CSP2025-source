#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    int arr[n*m];
    for(int i=0;i<(n*m);i++){
        cin>>arr[i];
    }
    int a1=arr[0];
    sort(arr,arr+(n*m),cmp);
    int r=0;
    for(int i=0;i<(n*m);i++){
        if(a1==arr[i]){
            r=i;
            break;
        }
    }
    int ansx=(r+n-1)/n,ansy;
    if(ansx%2==0){
        if(r%n==0)ansy=n;
        else ansy=r%n;
    }
    else{
        if(r%n==0)ansy=1;
        else ansy=(n+1)-(r%n);
    }
    cout<<ansx<<' '<<ansy;
    return 0;
}
