#include <bits/stdc++.h>
using namespace std;
int n,a[10086],s;
int main(){
    //freopen("polygon.in","r",stdin);
    //freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int i = 3;
    while(i<=n){
        for(int j = 1;j<=n;j++){
                int b = 0;
            for(int k = j;k<=i+j-1;k++){
                b+=a[k];
            }
            if(b>2*a[i+j-1])s++;
        }
    }
    cout<<s;
    return 0;
}
