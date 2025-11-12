#include<bits/stdc++.h>
using namespace std;
int b[105];
bool cmp(int a,int b){
    if(a<b) return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    cin>>b[1];
    int temp=0;
    temp=b[1];
    int s=n*m;
    for(int i=2;i<=s;i++){
        cin>>b[i];
    }
    sort(b+1,b+s+1,cmp);
    int a=0;
    for(int i=1;i<=s;i++){
        if(temp==b[i]) a=i;
    }
    if(a>n){
        if((a%n)%2!=0){
            cout<<a/n+1<<" ";
            if(a%n==0) cout<<n;
            else cout<<a%n;
        }
        else{
            cout<<a/n<<" ";
            if(a%n==0) cout<<1;
            else if(a%n==1) cout<<n;
            else cout<<n-a%n+1;
        }
    }
    else cout<<1<<" "<<a;
    return 0;
}
