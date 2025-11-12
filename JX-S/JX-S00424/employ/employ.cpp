#include <bits/stdc++.h>
using namespace std;
int n,m,t_1;
string s;
int a[510];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d %d",&n,&m);
    cin>>s;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<=n;i++)
        if(s[i]=='1')
            t_1++;
    if(n==m && t_1!=n){
         printf("0");
         return 0;
    }
    return 0;
}
