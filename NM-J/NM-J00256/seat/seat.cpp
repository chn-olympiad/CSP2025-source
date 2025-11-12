#include<bits/stdc++.h>
using namespace std;
int b[101]={};
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,m,x,y,nm=0;
    cin>>n>>m;
    cin>>x;
    b[x]=1;
    for(int i=1;i<n*m;i++){
        cin>>y;
        b[y]=1;
    }
    for(int i=100;i>=1;i--){
        if(i==x){
            nm+=1;
            break;
        }
        else if(b[i]==1){
            nm+=1;
        }
    }
    if(nm%n==0){
        if(nm/n%2==1){
            cout<<nm/n<<' '<<n;
        }
        else{
            cout<<nm/n<<' '<<1;
        }
    }
    else{
        if((nm/n+1)%2==1){
            cout<<nm/n+1<<' '<<nm%n;
        }
        else{
            cout<<nm/n+1<<' '<<n-nm%n+1;
        }
    }
    return 0;
}
