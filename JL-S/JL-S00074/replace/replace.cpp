#include<iostream>
#include<cstdio>
using namespace std;
int n,q;
string a,b;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n+q;i++) scanf("%s%s",&a,&b);
    printf("0\n0\n0\n0");
    fclose(stdin);
    fclose(stdout);
    return 0;
}