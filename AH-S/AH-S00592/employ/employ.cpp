#include<iostream>
#include<cstdio>
using namespace std;
long long n,cnt=1;
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n;
    getline(cin,s);
    getline(cin,s);
    getline(cin,s);
    cnt=1;
    for(int i=1;i<=n;i++){
        cnt*=i;
        cnt=cnt%988244353;
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
