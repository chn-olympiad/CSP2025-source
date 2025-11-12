#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m,i=0,jk[101],a1,j=0,x,y;
    cin>>n>>m;
    long long c=n*m,a[n*m+1];
    for(i=0;i<c;i++){
        cin>>a[i];
    }
    a1=a[0];
    for(i=0;i<100;i++){
        jk[i]=0;
    }
    for(i=0;i<c;i++){
        jk[a[i]]++;
    }
    j=0;
    for(i=100;i>=0;i--){
        if(jk[i]>0){
            a[j]=i;
            j++;
        }
    }
    for(i=0;i<c;i++){
        if(a1==a[i]){
            j=i+1;
            break;
        }
    }
    x=j/n;
    y=j%n;
    if(y==0){cout<<x;}
    else{cout<<x+1;}
    cout<<" ";
    if(x%2==0 && y==0){
        cout<<1;
    }
    else if(x%2==1 && y==0){
        cout<<n;
    }
    else if((x+1)%2==0){
        cout<<n-y+1;
    }
    else{
        cout<<y;
    }
    cout<<endl;
    return 0;
}
