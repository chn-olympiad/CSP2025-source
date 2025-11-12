
#include<bits/stdc++.h>
using namespace std;
int n,m,k,l;
int a[3000000],xo[3000000];
int p=0;
int main(){
    freopen("xor.out","w",stdout);
    freopen("xor.in","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1)p++;;
        if(a[i]<=1)k++;;
    }if(!(p-n)&&!m){
        cout<<(int)(n/2);
        return 0;
    }else if(k==n){
        if(!m){
            int t=2,ans=0;
            for(int i=1;i<=n;i++){
                if(!a[i]){
                    t=a[i];
                    ans+=!a[i];
                }else {
                    t--;
                    if(!t)ans+=t+1,t+=2;
                }
            }
            if(!t)ans++;
            cout<<ans;
        }else cout<<n;
    }

    return 0;;
}









/*
wahahahahayeee
i love tiannna!
saffeafwffewafw
I am monkey~
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
rp++
woshidog

*/
