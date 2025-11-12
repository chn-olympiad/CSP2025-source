
#include<bits/stdc++.h>
using namespace std;
int n,m;
int r;
int a[1000];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i = 0;i<n*m;i++){
        cin>>a[i];
        if(i == 0) r = a[i];
    }
    sort(a,a+n*m);
    for(int i = 0;i<n*m;i++){
        if(a[i] == r){
            int indexx = (n * m) - i;
            int y = indexx % n;
            if(y == 0) cout<<indexx / n<<" "<<m;
            else cout<<(indexx / n) + 1<<" "<<y;
            return 0;
        }
    }
    return 0;
}
