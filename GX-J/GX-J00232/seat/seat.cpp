#include<bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int N=n*m;
    for(int i=1;i<=N;i++){
        cin>>a[i];
    }
    int R=a[1];
    sort(a+1,a+N+1,cmp);
    for(int i=1;i<=N;i++){
        if(a[i]==R){
            cout<<1<<" "<<i;
            return 0;
        }
    }
    return 0;
}
