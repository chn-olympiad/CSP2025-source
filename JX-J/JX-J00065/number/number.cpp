#include<bits/stdc++.h>
using namespace std;
char a[2000005];
int b[100];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>a;
    for(int i=0;i<(int)strlen(a);i++){
        b[int(a[i]-'0')]++;
    }
    for(int i=9;i>=0;i--){
        for(int j=0;j<b[i];j++){
            cout<<i;
        }
    }
    return 0;
}
