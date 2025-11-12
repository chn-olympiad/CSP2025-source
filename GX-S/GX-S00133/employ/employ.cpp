#include<bits/stdc++.h>
using namespace std;
int a[1000];
string syx;
long long n,m,s,y,x,a;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    getline(cin,syx);
    for(long long i=0;i<=m-1;i++){
        cin>>a;
        if(syx[i]-48>a){
            cout<<syx[i-48];
        }
    }


return 0;

}
