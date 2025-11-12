#include<bits/stdc++.h>
using namespace std;
const int maxn=111;
int a[maxn];

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    cin>>a[n];
    for(int i=1;i<=n;i++){
        if(a[i]>a[i+1]){
            cout<<"1 1";
            return 0;
        }else if(a[i]<a[i+1]){
        cout<<n<<' '<<m;
        return 0;

        }
    }
    cout<<n<<' '<<m;
    return 0;
}

