#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long r,a[1111],x=1,y=1,sum=1;
bool cmp(long long a,long long b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>r;
    a[1]=r;
    for(long long i=2;i<=n*m;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+(n*m),cmp);
    int f=1;
    while(a[sum]!=r){
        if(y<n&&f==1){
            y++;
        }
        else if(y>1&&f==0){
            y--;
        }
        else{
            f=(f+1)%2;
            x++;
        }
        sum++;
    }
    cout<<x<<' '<<y;
    return 0;
}
