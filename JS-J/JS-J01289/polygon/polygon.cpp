#include <bits/stdc++.h>
using namespace std;

int n,a[5005],ans;

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    if(n<=3){
        if(n<3) cout << 0;
        else{
            int s=a[1],b=a[2],c=a[3];

            if(s+b>c || s+c>b || b+c>s){
                cout << 1;
            }else{
                cout << 0;
            }

        }
    }
    return  0;
}
