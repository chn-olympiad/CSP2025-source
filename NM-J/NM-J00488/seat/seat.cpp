#include<bits/stdc++.h>
using namespace std;
int a[150];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int y = 1;
    int x;
    for(int i=1;i<=n*m;i++){
            cin>>a[i];
    }
    int R = a[1];
    sort(a,a+n,cmp);
    for(int i=1;i<=n*m;i++){
        int x = i;
        if(a[x]==R){
            if(x>n){
                y++;
            }
        }
    }
    cout<<x<<" "<<y;
}
