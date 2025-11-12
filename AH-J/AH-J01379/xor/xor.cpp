#include<iostream>
#include<cstdio>
using namespace std;

int n;
long long k,a[200005];
int main() {
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i=n;i++) {
        cin>>a[i];
    }
    cout<<n/2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
