#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char a;
    char n[a];
    char b[105];
    ios::sync_with_stdio(false);
    cin>>n[a];
    for(int i = 0;i <= a;i++){
        if(n[i] != 1 or n[i] != 2 or n[i] != 3 or n[i] != 4 or n[i] != 5 or n[i] != 6 or n[i] != 7 or n[i] != 8 or n[i] != 9){
            n[i] = b[i];
        }
    }
    for(int i = 0;i <= 105;i++){
        if(n[i + 1] > n[i]){
            n[i + 1] = n[i];
        }
    }
    cout<<n<<"";
    return 0;
}
