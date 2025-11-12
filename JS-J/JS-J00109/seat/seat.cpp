#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
    freopen("seat3.in","r",stdin);
    freopen("seat3.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int t=a[1];
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m/2;i++){
        swap(a[i],a[n*m-i+1]);
    }
    int tot=1;
    int x=1,y=1;
    for(int i=1;i<=n*m;i++){
        if(a[tot]==t){
            cout<<y<<" "<<x<<endl;
            return 0;
        }
        if(y%2==1){
            x++;
            if(x>n){
                x--;
                y++;
            }
        }
        else {
            x--;
            if(x<1){
                x++;
                y++;
            }
        }
        tot++;
    }
    return 0;
}