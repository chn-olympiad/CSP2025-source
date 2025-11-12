#include<iostream>
using namespace std;

int n,m,r,cnt;
int a[200];
int n1,m1;
int s;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin>>n>>m;

    for(int i=0;i<n*m;i++){
        cin>>a[i];
        if(i==0){
            r=a[i];
        }
        if(a[i]>r){
            cnt++;
        }
    }

    cnt++;

    m1=cnt/n+1;
    if(cnt%n==0){
        m1--;
        s=n;
    }else{
        s=cnt%n;
    }

    if(m1%2==0){
        n1=n-s+1;
    }else{
        n1=s;
    }

    cout<<m1<<' '<<n1;

    return 0;
}
