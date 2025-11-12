#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k,idx=1;
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m >> k;
    for(int i=2;i<=n*m;i++){
        int x;
        cin >> x;
        if(x>k)idx++;
    }
    int col=((idx-1)/n)+1;
    int row;
    if(col%2==0){
        row=n-((idx-1)%n);
    }
    else{
        row=((idx-1)%n)+1;
    }
    cout << col << " " << row;
    return 0;
}
