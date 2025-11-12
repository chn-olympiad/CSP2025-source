#include<bits/stdc++.h>
using namespace std;
int n,m,c,f,g;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int b[n*m];
    int a[n*m];
    for(int i=0;i<n*m;i++){
        cin>>b[i];
    }
    int r=b[0];
    sort(b+0,b+n*m);
    int i=0;
    for(int j=m*n-1;j>=0;j--){
        a[i]=b[j];
        //cout<<a[i]<<endl;
        i++;
    }
    for(int i=0;i<n*m;i++){
        if(a[i]==r){
            c=i+1;
            break;
        }
    }
    int e;

    if(c%m==0){
        e=c/m;
    }else{
        e=c/m;
        e=e+1;
    }
    if(c>m){
        //cout<<"t";
        g=c%m;
    }else{
        g=c;
    }
    if(e%2==0){
        //cout<<"f";
        f=n-g+1;
    }else{
        f=g;
    }
    //cout<<c<<endl<<g<<endl<<r<<endl;
    cout<<e<<" "<<f;
    return 0;
}
