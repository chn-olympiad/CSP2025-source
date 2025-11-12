#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a1,x;
    cin>>n>>m>>a[1];
    a1=a[1];
    int s=n*m;
    for(int i=2;i<=s;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+s,cmp);
    for(int i=1;i<=s;i++){
        if(a[i]==a1){
            x=i;
            break;
        }
    }
    int t=x/n;
    if(x%n!=0){
        t++;
    }
    cout<<t<<" ";
    int ans=x-(t-1)*n;
    if(t%2==1){
        cout<<ans;
    }else{
        cout<<n+1-ans;
    }
    return 0;
}
