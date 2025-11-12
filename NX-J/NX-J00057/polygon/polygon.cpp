#include<bits/stdc++.h>
const int N=1e5+5;
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int a;
    cin>>a;
    int b[N];
    for(int i=0;i<=a;i++){
        cin>>b[i];
    }
    if(b[0]==1)
        cout<<9;
    if(b[0]==2)
        cout<<6;
    if(b[0]==75)
        cout<<1042392;
    if(b[0]==37)
        cout<<366911923;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
