#include<bits/stdc++.h>
using namespace std;
int n,m,cnt=1;
int a[105],hang,lie;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    for(int i=2;i<=n*m;i++){
        if(a[i]>a[1]){
            cnt++;
        }
    }
    hang=cnt/n+(cnt%n?1:0);
    if(hang%2){
        if(cnt%n)lie=cnt%n;
        else lie=n;
    }else lie=n-cnt%n+1;
    cout<<hang<<" "<<lie;
    return 0;
}
