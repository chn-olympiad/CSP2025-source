#include<bits/stdc++.h>
using namespace std;
int a[150];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int p=n*m;
    for(int i=1;i<=p;i++){
        cin>>a[i];
    }
    int point=a[1];
    int l;
    sort(a+1,a+p+1);
    for(int i=n;i>=1;i--){
        if(a[i]==point){
            l=i;
        }
    }
    int x=0,y=0;
    if(l%n==0){
        y=l/n;
    }else{
        y=l/n+1;
    }
    int k=l%n;
    if(k==0){
        k=n;
    }
    if(y%2==0){
        x=n-k+1;
    }else{
        x=k;
    }
    cout<<y<<' '<<x<<endl;
    return 0;
}