#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,count=0;
    cin>>n>>m;
    int a;
    vector<int> b(110,0);
    int r;
    cin>>r;
    b[r]++;
    for(int k=1;k<n*m;k++){
            cin>>a;
            b[a]++;
    }
    for(int k1=100;k1>=0;k1--){
            if(k1==r)break;
        count+=b[k1];
    }
    if((count/n)%2==1){
        cout<<(count/n)+1<<" "<<n-count%n;
    }else{
        cout<<(count/n)+1<<" "<<count%n+1;
    }
    return 0;
}
