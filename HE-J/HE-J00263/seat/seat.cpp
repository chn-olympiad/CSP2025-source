#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
pii a[200];
int n,m;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i].first;
        a[i].first=100-a[i].first;
        a[i].second=i;
    }
    sort(a,a+n*m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!a[i*m+j].second){
            cout<<i+1<<' '<<((i%2)?(m-j):(j+1));
            return 0;
        }}
    }
    return 0;
}
