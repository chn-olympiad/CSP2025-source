#include<iostream>
#include<cstdio>
#define N 10001
using namespace std;
int a[101];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,x,y;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>x;
        a[x]++;
        if(!i)y=x;
    }
    int cnt=0;
    for(int i=100;i>=y;i--){
        cnt+=a[i];
    }
    //cout<<cnt<<endl;
    if(((cnt-1)/n+1)&1){
        //cout<<"fst";
        if(cnt%n==0){
            cout<<cnt/n<<" "<<n;
        }
        else cout<<((cnt-1)/n+1)<<" "<<(cnt%n);
    }
    else{
        //cout<<"sec";
        if(cnt%n==0){
            cout<<cnt/n<<" "<<1;
        }
        else cout<<((cnt-1)/n+1)<<" "<<(n-(cnt%n)+1);
    }
    return 0;
}
