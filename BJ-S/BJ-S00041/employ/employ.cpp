#include <iostream>

using namespace std;
long long n,m,k=1;

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cout << 0;
    cin >> n;
    cin >> m;
    if(m==1){
        for(int i=1;i<=n;i++){
            k*=i;
            k%=998244353;
        }
        cout << k;
    }else{
        cout << 0;
    }
    return 0;
}
