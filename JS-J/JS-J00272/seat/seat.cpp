#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10004];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int cnt=a[1];
    sort(a+1,a+1+(n*m));
    int num;
    for(int i=1;i<=n*m;i++){
        if(a[i]==cnt){
            num=i;
            break;
        }
    }
    int x,y;
    num=n*m-num+1;
    //cout<<num<<" ";
    if(num%n==0){
        x=num/n;
        //cout<<x<<" ";
        if(x%2==0){
            y=1;
        }else{
            y=n;
        }
    }else{
        x=num/n+1;
        y=num%n;
        if(x%2==0){
            y=n-y+1;
        }
    }
    cout<<x<<" "<<y<<endl;
    return 0;
}
