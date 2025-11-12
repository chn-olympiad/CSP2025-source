#include <bits/stdc++.h>
using namespace std;
int n,k;
int main(){
   freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    int a[n+1],s=0,x,i=1;
    for (i=0;i<=n;i++)cin>>a[i];//
    for (i=0;i<=n;i++){cout<<1;
        if(a[i]==k) {s++; a[i]=0;}
        else{
            if(a[n]==0){break;}
            else while(a[i]!=k) {
                    x=1;
                    if(a[i]>k){ a[i]=max(a[i],a[i+x])-min(a[i],a[i+1]); a[i+x]=0;}
                    else      {a[i]=max(a[i],a[i+x])+min(a[i],a[i+1]); a[i+x]=0;}
                    x++;
                }
            s++;
        }
    }
    cout<<s;
    return 0;
}
