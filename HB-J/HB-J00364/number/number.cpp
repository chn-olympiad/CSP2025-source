#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int num[15];
string kkk;
char k;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>kkk;
    for(int i=0;i<kkk.size();i++){
        k=kkk[i];
        if(k<='9'&&k>='0')
            num[k-'0']++;
    }
    for(int i=9;i>=0;i--)
        for(int j=0;j<num[i];j++)
            printf("%d",i);
    return 0;
}
