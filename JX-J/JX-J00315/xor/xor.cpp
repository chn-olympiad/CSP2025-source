#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,ma,d[100001],a[100001],k,x[100001],xl=1,t,len=1;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    x[1]=0x7fffffff;
    while(cin>>a[n++]);
    d[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        if(a[i]<=d[len]){
        d[len++]=a[i];
        }else{
            len--;
             }
    cout<<len-1<<endl;
    for(int i=1;i<=n;i++)
    {

        t=0;
        if(x[xl]<a[i])
        {
            xl++;
            x[xl]=a[i];
        }else{
        int k=lower_bound(x+1,x+xl+1,a[i])-x;
        }
    }
}
    cout<<xl;
return 0;
}
