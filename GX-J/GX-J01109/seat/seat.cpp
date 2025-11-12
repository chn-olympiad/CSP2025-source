#include<bits/stdc++.h>
using namespace std;
bool p(long long int a,long long int b){
    return a>b;
}
int main(){
   freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m;
    long long n1=0,m2=0;
    long long r=0;
    cin>>n>>m;
    long long sum=n*m;
    long long a[100010];
    for(long long i=0;i<sum;i++){
        cin>>a[i];
    }
    r=a[0];
    sort(a,a+sum,p);
    for(long long i=0;i<sum;i++){
        if(a[i]==r){
            if(i+1<=n){
            cout<<"1"<<" "<<i+1<<endl;
            break;
            }
            else if(i+1<=2*n){
                cout<<"2"<<" "<<(2*n-i);
            }
            else if(i+1<=3*n){
                cout<<"3"<<" "<<(i+1)-2*n;
            }
            else if(i+1<=4*n){
                cout<<"4"<<" "<<(4*n-i);
            }
            else if(i+1<=5*n){
                cout<<"5"<<" "<<(i+1)-4*n;
            }
            else if(i+1<=6*n){
                cout<<"6"<<" "<<(6*n-i);
            }
            else if(i+1<=7*n){
                cout<<"7"<<" "<<(i+1)-6*n;
            }
            else if(i+1<=8*n){
                cout<<"8"<<" "<<(8*n-i);
            }
            else if(i+1<=9*n){
                cout<<"9"<<" "<<(i+1)-8*n;
            }
            else cout<<"10"<<" "<<(10*n-i);
        }
    }
    return 0;
}
