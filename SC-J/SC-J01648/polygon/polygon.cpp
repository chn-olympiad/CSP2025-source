#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon2.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin >> n;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    int sum_=0;
    for(int i=1;i<=n-2;i++){
        for(int j=3;j<=n;j++){
            int b[j]={0};
            int max_=0,sum=0;
            for(int m=1;m<=j;m++){
                b[m]=a[m];
                max_=max(max_,b[m]);
                sum+=b[m];
            }
            if(sum>=2*max_){
                sum_++;
            }
        }
    }
    cout << sum_;
    fclose(stdin);
    fclose(stdout);
    return 0;
}