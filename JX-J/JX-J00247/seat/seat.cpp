#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,R;
int a[N];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    R=a[1];
    sort(a+1,a+1+n*m,cmp);
    int x=1,y=1;
    for(int i=1;i<=n*m;i++){
        if(a[i]==R){
            cout<<x<<" "<<y;
            return 0;
        }
        if(x%2==1){
            if(y==n) x++;
            else y++;
        }
        else{
            if(y==1) x++;
            else y--;
        }
    }
    return 0;
}
