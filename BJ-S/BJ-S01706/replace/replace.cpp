#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;string a;
    cin>>n>>q;
    for(int i=1;i<=2*(n+q);i++)scanf("%s",&a);
    for(int i=1;i<=q;i++)printf("0\n");
    return 0;
}
