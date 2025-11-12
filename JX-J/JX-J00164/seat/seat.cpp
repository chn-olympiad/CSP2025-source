#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,w;
    cin>>n>>m;
    int a[105];
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(i==1){
            int w=a[i];
        }
    }
    for(int i=1;i<=n*m;i++){
        for(int j=1;j<n*m;j++){
            if(a[j]<a[j+1]){
                int q=a[j];
                a[j]=a[j+1];
                a[j+1]=q;
            }
        }
    }
    for(int i=1;i<=n*m;i++){
        if(w == a[i]){
            if((i/n)%2 == 0){
                cout<<i/n<<' '<<n-(i%n)+1;
                return 0;
            }
            else if((i/n)%2 == 1){
                cout<<i/n<<' '<<i%n;
                return 0;
            }
        }
    }
    return 0;
}
/*



                     _______                        _   _   _
        ___         | ______|      _______         | |_| |_| |      __
       /  /         | ______|     |___  __|        |____  ___|     |  |
      /   \         | |_\ \_         / /__             / /_        |  |
     /  /\ \        | ____  |       / __  \           / __ \       |  |
    /  /  \ \       | |_  \ \_     / / _/ /          / / / /       |  |
   /__/    \_\      |__/   \_/    /_/  \_/          /  \/ /        |  |
                                                   /_/\  /         |__|
                                                      / /           __
                                                     / /           |  |
                                                    / /            |__|
                                                   /_/


*/
