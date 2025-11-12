#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    scanf("%d",&n);
    if(n==3){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if((a+b+c)>max(a,max(b,c))*2)printf("1");
        else printf("0");
        return 0;
    }else{
        printf("Noooooooo!!!!!!!!!!I've been zuojud by stick!!!!!!!!!!I can't AK CSP-J 2025 R2!!!!!!!");
    }
}
