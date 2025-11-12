#include<bits/stdc++.h>
using namespace std;

int n,m,sum,num,c,r,score;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    sum=n*m;
    vector<int>a(sum);
    for(int i=0;i<sum;i++){
        cin>>a[i];
    }
    score=a[0];
    sort(a.begin(),a.end());
    for(int i=sum-1;i>=0;i--){
        if(a[i]==score){
            num=sum-i;
            break;
        }
    }
    c=(num+n-1)/n;
    if(c%2){
        r=num%n;
        if(r==0)r=n;
    }
    else{
        r=n+1-num%n;
        if(r==n+1)r=1;
    }
    cout<<c<<' '<<r;
    return 0;
}
