#include <bits/stdc++.h>
using namespace std;
int a[500010],n,k,u,b=1,s=0;
int main(){
    freopen("xor.in","r",stdin);        freopen("xor.out","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    u=a[1];
    for (int i=2;i<=n;i++){
        if (u==k){
            s+=1;
            u=a[i];
            if (i>n) break;
            i++;
        }
        u^=a[i];
    }
    if (u==k) s+=1;
    cout<<s;
    fclose(stdin);      fclose(stdout);
    return 0;
}