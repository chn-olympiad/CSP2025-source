#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[109],R;
    cin >> n >> m;
    for(int i=1;i<=n*m;i++){
        cin >> a[i];
    }
    R=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int c=1;c<=n;c++){
        if(c%2==1){
            for(int r=1;r<=m;r++){
                if(a[((c-1)*m)+r]==R){
                    cout << c << " " << r;
                }
            }
        }
        else {
            for(int r=m;r>=1;r--){
                if(a[(c*m)-r+1]==R){
                    cout << c << " " << r;
                }
            }
        }
    }
    return 0;
}
