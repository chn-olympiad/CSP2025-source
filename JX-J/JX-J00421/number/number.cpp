#include <bits/stdc++.h>
using namespace std;

int a[1001]={};
int main (){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    scanf("%s",s);
    int maxn=0;
    for(int i=1;i<='s';i++){
        while('s'>='1'&&'s'<='9'){
            if('s'>maxn){
                maxn='s';
            }maxn+='s';
        }
    }cout<<maxn;
    return 0;
}
