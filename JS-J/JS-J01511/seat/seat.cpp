#include<iostream>
using namespace std;
int n=0,m=0,p,g;
int num=0;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>p;
    for(int i=1;i<n*m;i++){
        cin>>g;
        if(g>p)num++;
    }
    cout<<(num/n)+1<<" ";
    if(((num/n)+1)%2==0){
        cout<<n-(num%n);
    }else{
        cout<<(num%n)+1;
    }
    return 0;
}
