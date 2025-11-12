#include<bits/stdc++.h>
using namespace std;
const int N=200;
int a[N];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int f=a[1];
    int cnt=0;
    sort(a+1,a+n*m+1,greater<int>());
    for(int i=1;i<=n*m;i++){
        if(a[i]==f){
            cnt=i-1;
            break;
        }
    }
    int c=1;
    m=1;
    c+=cnt/n;
    if(c%2!=0){
        m+=cnt%n;
    }
    else{
        m+=(n-(cnt%n)-1);
    }
    cout<<c<<" "<<m;
    return 0;
}

