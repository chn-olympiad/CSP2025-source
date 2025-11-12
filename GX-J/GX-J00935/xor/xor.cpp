#include <iostream>
using namespace std;
const int N=5*1e5+5;
int a[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,cnt=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==0)
            cnt++;
    }
    if(k==1)
        cout<<n-cnt;
    else
        cout<<(n-cnt)/2;
    return 0;
}
