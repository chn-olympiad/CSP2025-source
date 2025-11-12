#include<bits/stdc++.h>
using namespace std;
short a[10005];
bool cmp(short a,short b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    short n,m;
    cin>>n>>m;
    long long sum=m*n;
    for(int i=1;i<=sum;i++){
        cin>>a[i];
    }
    int b=a[1];
    sort(a+1,a+sum+1,cmp);
    long long cnt=0;
    for(int i=1;i<=sum;i++){
        if(a[i]==b){
            break;
        }else{
            cnt++;
        }
    }
    int r=(cnt%n);
    int c=cnt/n+1;
    if(c%2==0){
        cout<<c<<' '<<m-r;
    }else{
        cout<<c<<' '<<r+1;
    }
    return 0;
}
