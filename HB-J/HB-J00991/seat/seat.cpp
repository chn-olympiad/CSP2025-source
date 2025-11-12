#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[121];
int R;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int len=n*m;
    cin>>R;
    a[1]=R;
    for(int i=2;i<=len;i++){
            cin>>a[i];
    }
    sort(a+1,a+len+1,cmp);
    int pl=0;
    for(int i=1;i<=len;i++){
        if(a[i]==R){
            pl=i;
        }
    }
    int k=pl;
    int t=1;
    while(k>n){
        k-=n;
        t++;
    }
    if(t%2==0){
        k=n+1-k;
    }
    cout<<t<<" "<<k<<endl;
    return 0;
}
