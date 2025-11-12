#include<bits/stdc++.h>
using namespace std;
int main(){

    int n,m;
    int s;
    int a;
    int num=0;
    cin>>n>>m;
    cin>>a;
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    for(int i=0;i<n*m-1;i++){
        cin>>s;
        if(s>a){
           num++;
        }
    }
    if(num<n){
        cout<<"1"<<" "<<num;
    }
    else if(num==n){
        cout<<"2"<<" "<<n;
    }
    else if((num/n+1)%2==0&&num>n){
        cout<<num/n+1<<" "<<n-num%n;
    }
    else if((num/n+1)%2==1&&num>n){
        cout<<num/n+1<<" "<<num%n+1;
    }

    return 0;

}
