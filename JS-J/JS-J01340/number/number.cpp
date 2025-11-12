#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e6+10;

char c[MAXN];
int a[10];

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>c;
    for(int i=0;i<strlen(c);i++){
        if(isdigit(c[i])){
            a[int(c[i])-int('0')]++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=a[i];j++){
            cout<<i;
        }
    }
    return 0;
}
