#include<bits/stdc++.h>
using namespace std;
int a[15],n,m,k,ans,tot;
char c[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",c);
    for(int i=0;c[i];i++){
        if(c[i]>='0'&&c[i]<='9'){
            a[c[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        while(a[i]--){
            printf("%d",i);
        }
    }
    cout<<'\n';
    return 0;
}
