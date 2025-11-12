#include<bits/stdc++.h>
using namespace std;
long long a[5010],ans,n,maxa=-2147483647,xx,h=0;
bool b[5010];
void js(int x)
{
    for(int i=1;i<=n;i++){
        b[i]=1;
        js(x-1);
        maxa=max(maxa,a[i]);
        h+=a[i];
        b[i]=0;
        if(x==xx){
            if(h>2*maxa) ans++;
        }
    }
}
int main()
{
    freopen("polygon1.in","r",stdin);
    //freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=3;i<=n;i++){
        xx=i;
        js(i);
    }
    cout<<ans;
}
