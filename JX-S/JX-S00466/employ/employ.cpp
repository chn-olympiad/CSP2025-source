#include<bits/stdc++.h>
using namespace std;
int a,b;
string c;
int d[10000];
int main(){
freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);
    cin>>a>>b;
    cin>>c;
    for(int i=1;i<=a;i++){
        cin>>d[i];
    }
    long long int all=c.size();
    for(int i=1;i<=c.size()-2;i++){
        all*=(all-i);
    }
    cout<<all;
    return 0;
}
