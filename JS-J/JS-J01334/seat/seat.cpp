#include <bits/stdc++.h>
using namespace std;
int a[150];
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int R;
    cin>>R;
    int cnt=0;
    for (int i=2;i<=n*m;i++){
            cin>>a[i];
            if (a[i]>R){
                cnt++;
            }
    }
    int c=cnt/n+1;
    if (c%2==1){
        cout<<c<<1+cnt%n<<endl;
        return 0;
    }
    else if (c%2==0){
        cout<<c<<n-cnt%n<<endl;
        return 0;
    }
    return 0;
}
