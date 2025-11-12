#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
using big = long long;

int a[205],n,m;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[(i-1)*m+j];
        }
    }
    int chk=a[1];
    sort(a+1,a+n*m+1,greater<int>());
    int r=1,c=1;
    for(int i=1;i<=n*m;i++){
        if(a[i]==chk){
            cout<<c<<" "<<r;
            break;
        }
        if(c&1){
            if(r==n) c++;
            else r++;
        }
        else{
            if(r==1) c++;
            else r--;
        }
    }
    return 0;
}

