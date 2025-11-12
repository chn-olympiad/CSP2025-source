#include <bits/stdc++.h>
using namespace std;
const int N=109;
int n,m;
int a[N],r=1,c=1,o;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;++i)cin>>a[i];o=a[1];
    sort(a+1,a+n*m+1,greater<int>());
    for(int i=1;i<=n*m;++i){
        if(a[i]==o){
            cout<<c<<" "<<r;
            return 0;
        }
        if(c%2==1){
            r++;
            if(r>n)r=n,c++;
        }
        else{
            r--;
            if(r==0)r=1,c++;
        }
    }
    return 0;
}
