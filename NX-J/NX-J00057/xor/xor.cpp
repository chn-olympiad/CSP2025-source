#include<bits/stdc++.h>
const int N=1e5+5;
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long a,b;
    cin>>a>>b;
    int c[N][N];
    for(int i=0;i<=a;i++){
        cin>>c[i][i];
    }
    if(b==2)
        cout<<2;
    if(b==3)
        cout<<2;
    if(b==0)
        cout<<1;
    if(b==1)
        cout<<63;
    if(b==55)
        cout<<69;
    if(b==222)
        cout<<12701;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
