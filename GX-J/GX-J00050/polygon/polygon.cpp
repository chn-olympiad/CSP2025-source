#include<bits/stdc++.h>
using namespace std;
const int sum1=998244353;
int n,a[5001];
long long a1[5001];
long long num1;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        a1[i]=a1[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+2;j<=n;j++){
            int p=a1[j]-a1[i]+a[i];
            if(p>a[j]*2){
                num1++;
                num1=num1%sum1;
            }
            for(int k=i+1;k<j;k++){
                p=a1[j]-a1[i]+a[i]-a[k];
                if(p>a[j]*2){
                    num1++;
                    num1=num1%sum1;
                }
            }
        }
    }
    cout<<num1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
