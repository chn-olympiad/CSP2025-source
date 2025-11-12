#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long n,m,cnt=1,numberss,c,r,myn;
int a1,datass;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(long long i=0;i<(n*m);i++){
        cin>>datass;
        if(i==0){a1=datass;continue;}
        if(datass>a1)++cnt;
    }
    c=cnt/n;
    if(cnt%n!=0)c+=1;
    if(c%2==1){
        if(cnt<=n)r=cnt;
        else r=cnt%n;
    }
    else{
        r=1+n-(cnt%n);
    }
    cout<<c<<" "<<r;
    return 0;
}
