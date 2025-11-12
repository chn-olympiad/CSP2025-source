#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <queue>
using namespace std;
int n,sum,ma,m;
int a[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        sum=0,ma=0;
        for(int j=i;j<=n;j++){
            sum+=a[i];
            ma=max(ma,a[i]);
            if(sum>ma*2){
                cout<<i<<" "<<j<<endl;
                m=(m+1)%998244353;
            }
        }
    }
    cout<<m;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
