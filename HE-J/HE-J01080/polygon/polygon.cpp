#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen ("polygon.in","r",stdin);
    //freopen("polygon.out","w",stdout);

    int n,a[n],b[n],ans=0;
    int c=0;
    cin >>n;
    for(int i=0;i<n;i++){
        cin >> a[i];

    }
    while(n--){
        for(int i=n-1;i>=2;i--){
            b[i]=a[i]+a[i-1];
            if(b[i]*2>a[i]){
            ans++;
            }
        }
    }
    cout<<ans;


    //fclose(stdin);
    //fclose(stdout);
    return 0;
}

