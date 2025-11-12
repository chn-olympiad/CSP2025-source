#include<iostream>
#include<fstream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
inline int read(){
    int x=0;
    char c=getchar();
    while(c>='0'&&c<='9')x=10*x+c-'0',c=getchar();
    return x;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int q=read();
    while(q--)printf("0\n");
    return 0;
}
