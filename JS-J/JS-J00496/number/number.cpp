#include <bits/stdc++.h>
using namespace std;


const int N = 1e6+10;
char c,a[N];
int q[N],n,ans;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",a);
    for(int i = 0;a[i]!='\0';i++){
        c=a[i];
        if(c-'0'>=0&&c-'0'<=9){
            q[n++]=c-'0';
        }
    }
    sort(q,q+n);
    for(int i = n-1;i >= 0;i--){
        printf("%d",q[i]);
    }
    return 0;
}
