#include<bits/stdc++.h>
using namespace std;
int n , q ;
char s[1010][1010] , t[1010][1010] ;
char ss[1010][1010] , tt[1010][1010] ;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%s%s",s[i]+1,t[i]+1);
    }
    for(int i=1;i<=q;i++){
        scanf("%s%s",ss[i]+1,tt[i]+1);
        int ls=strlen(ss[i]+1) , lt=strlen(tt[i]+1) ;
        if(ls!=lt){printf("0\n");continue;}
    }
    return 0;
}
