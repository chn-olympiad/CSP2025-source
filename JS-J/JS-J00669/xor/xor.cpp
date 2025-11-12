#include <iostream>

using namespace std;
int n,k;
int R[100000];
int sum1;
int sum2;
int maxn=0;
int main()
{
    freopen("xor.in","w",stdin);
    freopen("xor.out","r",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>R[i];
    }
    cout<<n;
    fclose(stdin);
    fclose(stdout);

    return 0;
}
