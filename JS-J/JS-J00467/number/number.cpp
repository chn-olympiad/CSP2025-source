#include<bits/stdc++.h>
using namespace std;
int a[11];
char c;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    memset(a,0,sizeof(a));
    c=getchar();
    while((c>='0'&&c<='9')||(c>='a'&&c<='z')){
        if(c>='0'&&c<='9'){
            a[c-'0']++;
        }
        c=getchar();
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=a[i];j++){
            cout<<i;
        }
    }
    return 0;
}
