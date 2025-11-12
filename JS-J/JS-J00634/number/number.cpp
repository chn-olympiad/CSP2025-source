#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string b;
    char a[100005];
    long long c[100005];
    long long i=0,j,x=0;
    cin>>b;
    for(i=0;i<b.size();i++){
        if(b[i]>='0'&&b[i]<='9'){
            c[x]=int(char(b[i])-48);
            x++;
        }
    }
    std::sort(c,c+x+1);
    for(i=x;i>=1;i--) cout<<c[i];
    return 0;
}
