#include <bits/stdc++.h>
using namespace std;
int n,m,a[101],k;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n*m;i++) cin>>a[i];
    k=a[1];
    sort(a+1,a+1+n*m,greater <int>());
    int hang=1,lie=1;
    for (int i=1;i<=n*m;i++){
        if (a[i]==k){
            cout<<hang<<" "<<lie;
            return 0;
        }
        if (hang&1==1){
            if (lie==n) hang++;
            else lie++;
        }
        else{
            if (lie==1) hang++;
            else lie--;
        }
    }
    return 0;
}
