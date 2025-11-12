#include<bits/stdc++.h>
using namespace std;
int n[32564],m[346654];
int main(){
    freopen("seat.in",'r',stdin);
    freopen("seat.out",'w',stdout);
    int a,b;
    cin>>a>>b;
    for(int i=1;i<=a*b;i++){
        cin>>n[i];
    }
    int cnt=n[1];
    sort(n+1,n+1+a*b);
    for(int i=1;i<=a*b/2;i++){
        m[i]=n[a*b-i+1];
        n[a*b-i+1]=n[i];
        n[i]=m[i];
    }
    int c;
    for(int i=1;i<=a*b;i++){
        if(n[i]==cnt){
            c=i;
        }
    }
    int d=c/a,f=c%a;
    if(f==0){
        cout<<d<<" ";
        if(d%2==0){
            cout<<1;
        }
        else{
            cout<<a;
        }
    }
    if(f>0){
        cout<<d+1<<" ";
        if((d+1)%2==1){
            cout<<f;
        }
        else{
            cout<<a-f+1;
        }
    }
    return 0;
}
