#include <bits/stdc++.h>
using namespace std;

const int N=15;
long long n;
long long m;
long long a[N*N];

bool cmp(long long a,long long b){
    return a>b;
}

int main(){

    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);


    cin>>n>>m;
    for(long long i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int stdr=a[1];// mark r's score
    int pos=-1;
    sort(a+1,a+1+n*m,cmp);//sort to get the highest scores
    for(long long i=1;i<=n*m;i++){
        if(a[i]==stdr){
            pos=i;
            break; // find r's position
        }
    }
    // calculate
    //1.column
    long long column_num=ceil(pos*1.0/n);
    long long higher=pos-1;
    cout<<column_num<<" ";
    long long higher_col=(pos-1)/n;
    long long remain=(pos-1)-higher_col*n;
    if(column_num%2==1){
        cout<<remain+1;
    }else{
        cout<<n-remain;
    }
    return 0;
}
