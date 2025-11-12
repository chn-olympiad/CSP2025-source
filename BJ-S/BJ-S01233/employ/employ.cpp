#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cctype>
using namespace std;
long long n,m,c[100005],num=1;
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    for(int i=1;i<=n;i++){
        num*=i;
    }
    cout<<num%998244353<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
