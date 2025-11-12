#include<bits/stdc++.h>
using namespace std;

const int N = 1e2 + 10;

int n,m;
int ne = 1;
int now;
int x;
int hang,lie;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>x;
    for(int i = 2;i <= n * m;i++){
        cin>>now;
        if(x < now) ne++;
    }
    if(ne % n == 0){
        if((ne / n) % 2 == 1) cout<<ne / n<<" "<<n;
        else cout<<ne / n<<" "<<1;
    }else{
        cout<<(ne - ne % n) / n + 1<<" ";
        if(((ne - ne % n) / n) % 2 == 1) cout<<n - ne % n + 1;
        else cout<<ne % n;

    }
}
