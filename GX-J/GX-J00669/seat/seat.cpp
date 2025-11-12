#include<bits/stdc++.h>
using namespace std;
int n,m;
int a=0,c=0,h=0;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    c=n*m;
    long long e[c];
    for(int i=1;i<=c;i++){
        cin>>e[i];
        a=e[1];
    }
    sort(e+1,e+1+c);
    for(int i=1;i<=c;i++){
        if(e[i]==a){
            h=i;
        }
    }
    if(h==1){
        cout<<"1"<<"1";
        return 0;
    }
    int nn=0,nm=0;
    if(h%n==0){
        nn=n;
    }else{
        nn=h%n;
    }
    nm=h/m;
    if(h%m!=0){
        nm++;
    }
    cout<<nn<<" "<<nm<<endl;
    return 0;
}
