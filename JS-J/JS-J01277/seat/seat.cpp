#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
#define ll long long
int a[maxn];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,mark;
    cin>>n>>m;
    int k=n*m;
    for(int i=1;i<=k;i++){
        cin>>a[i];
    }
    mark=a[1];
    sort(a+1,a+k+1);
    for(int i=k;i>=1;i--){
        if(a[i]==mark){
            int x=(k-i)/n+1;
            int y=(k-i)%n+1;
            if(x%2==0){
                cout<<x<<" "<<n-y+1;
            }
            else cout<<x<<" "<<y;
            break;
        }
    }
    return 0;
}
