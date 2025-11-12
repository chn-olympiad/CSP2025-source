#include<iostream>
#include<algorithm>
using namespace std;
bool(int a,int b){
    if(a>b){
        return true;
    }
    if(b>a){
        return false;
    }
}
int main(){
{
    freopen("seat.in","r","std.in");
    freopen("seat.out","w","std.out");
    int a[100086],c=1,r=1,n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int d=a[1];
    sort(1,a+1,std(a,b));
    for(int i=1;i<=100086;i++){
        if(r%2==0){
            c++;
        }
        if(r%2==1){
            c--;
        }
        if(c==abs(-m-1)||c==1+m){
            r++;
        }
        if(a[i]==d){
            cout<<c<<" "<<r;
            return 0;
        }
    }
}
