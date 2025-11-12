#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[10005],m;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<n;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
