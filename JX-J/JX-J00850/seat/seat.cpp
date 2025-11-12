#include <bits/stdc++.h>
using namespace std;
int n,m,s[200];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    int r,k;
    for(int i = 1;i<=n*m;i++) cin >> s[i];//O(nm)
    r = s[1];
    sort(s+1,s+1+n*m,cmp);//O(nlogn)
    for(int i = 1;i<=n*m;i++){
        if(s[i] == r){
            k = i;
            break;
        }
    }
    int lie = (k-1)/n+1;
    int hang = 0;
    cout << lie << " ";
    if(lie % 2 == 1){
        hang = k-(lie-1)*n;
    }
    else{
        hang = n-(k-(lie-1)*n)+1;
    }
    cout << hang;
    return 0;
}
