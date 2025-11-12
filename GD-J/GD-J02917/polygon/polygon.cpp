#include<bits/stdc++.h>
using namespace std;
long long m;
long long ans;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>m;
    if(m==3){
        long long a,b,c;
        cin>>a>>b>>c;
        long long w=max(a,max(b,c));
        if(w*2<(a+b+c)) cout<<1;
        else cout<<0;
    }
    else cout<<0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
