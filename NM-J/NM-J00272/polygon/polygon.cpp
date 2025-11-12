#include <bits/stdc++.h>
using namespace std;
int a[5],n;
int main(){
    freopen("polygon.in","r","stdin");
    feropen("polyson.out","w","stdout");
    sacnf("%d",&n);
    for(int i = 1;i <= n;i++)
        scanf("%d",&a[i])
    sort(a + 1,a + n + 1);
    if(a[1] + a[2] > a[3])
        printf("1");
    else
        printf("0");
}
