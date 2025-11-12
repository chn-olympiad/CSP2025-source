#include<bits/stdc++.h>

using namespace std;

const int N=15;
int a[N];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,rec=0;
    cin >> n >> m;
    int t=n*m;
    for(int i=1;i<=t;i++) cin >> a[i];
    int k=a[1];
    sort(a+1,a+t+1,cmp);
    for(int i=1;i<=t;i++){
        if(a[i]==k) rec=i;
    }
    int x,y;
    if(rec%n!=0) x=rec/n+1;
    else x=rec/n;
    if(x%2==1){
        if(rec%n==0) y=n;
        else y=rec%n;
    }
    else{
        if(rec%n==0) y=1;
        else y=n-rec%n+1;
    }
    cout << x << ' ' << y;
    return 0;
}
