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
int n,k,m,z,q;
int r[500005];
int a[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>r[i];
    }
    for(int i=1;i<=n;i=q+1){
            z=0;
        for(int j=i;j<=n;j++){
            z^=r[j];
            if(z==k){
                m++;
                q=j;
                break;
            }
        }
    }
    cout<<m;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
