#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,c=0;
    scanf("%d%d",&n,&m);
    char s[n+1];
    int g[n+1];
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    for(int i=1;i<=n;i++){
        cin>>g[i];
    }
    for(int i=1;i<=n;i++){
        if(s[i]==1){
            c++;
        }
    }
    printf("%d",c);
}
