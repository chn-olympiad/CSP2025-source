#include<bits/stdc++.h>
using namespace std;
long long n;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n;
    if(n%2==0&&n!=2) cout<<n%2;
    else cout<<0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
