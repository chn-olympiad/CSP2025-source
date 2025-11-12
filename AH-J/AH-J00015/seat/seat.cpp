#include<bits/stdc++.h>
using namespace std;
int n,m,sum,smallR;
int a[105];

bool cmp(int x,int y){
    return x>y;
}

int main (){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    sum=n*m;
    for(int i=1;i<=sum;i++){
            cin>>a[i];
    }
    smallR=a[1];
    sort(a+1,a+1+sum,cmp);
    for(int i=1;i<=sum;i++){
        if(a[i]==smallR){
            if((int)ceil(i*1.0/n)%2==0){
                if(i%n==0){
                    cout<<(int)ceil(i*1.0/n)<<" "<<1<<endl;
                }else{
                    cout<<(int)ceil(i*1.0/n)<<" "<<n-i%n+1<<endl;
                }
            }else{
                if(i%n==0){
                    cout<<(int)ceil(i*1.0/n)<<" "<<n<<endl;
                }else{
                    cout<<(int)ceil(i*1.0/n)<<" "<<i%n<<endl;
                }
            }
            break;
        }
    }
    return 0;
}
