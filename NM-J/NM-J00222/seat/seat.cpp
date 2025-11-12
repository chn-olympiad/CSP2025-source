#include <bits/stdc++.h>
using namespace std;
int a[15][15];
int b[1000];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>b[i];
    }
    int c=b[1];
    sort(b+1,b+n*m+1);
    int x=1,y=1;
    int cnt=1;
    for(int i=1;i<=n*m;i++){
        if(cnt%2==1){
            a[x][y]=b[n*m-i+1];
            if(a[x][y]==c) {
			cout<<x<<" "<<y;
			break;
			}
            x++;
            if(x>n){
                y++;
                x=n;
                cnt++;
            }
        }
        else{
            a[x][y]=b[n*m-i+1];
            if(a[x][y]==c) {
			cout<<x<<" "<<y;
			break;
			}
            x--;
            if(x<1){
                y++;
                x=1;
                cnt++;
            }
        }
    }
    return 0;
}
