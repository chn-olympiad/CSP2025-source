#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template <class T>
void read(T& a){
    a=0;char ch=getchar();
    while(ch<'0' || ch>'9') ch=getchar();
    while(ch>='0' && ch<='9'){
        a=(a<<1)+(a<<3)+ch-'0';
        ch=getchar();
    }
}

int main(){
    #ifndef Db
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    #endif

    return 0;
}

