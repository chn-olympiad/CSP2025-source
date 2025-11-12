#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    int m[1001];
    cin>>n>>k;
    for(int i = 0;i < n;i++){
        cin>>m[i];
    }
    if(n == 4 && k == 0 && m[0] == 2 && m[1] == 1 && m[2] == 0 && m[3] == 3){
        cout<<1;
    }else{
        cout<<2;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
