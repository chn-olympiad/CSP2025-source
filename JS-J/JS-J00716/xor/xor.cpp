#include<bits/stdc++.h>
using namespace std;
int a[500005];
bool book[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,f=1;
    int ans=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1) f=0;
    }
    if(k==0&&f){
        cout<<n/2;
    }else{
        for(int i=1;i<=n;i++){
            if(a[i]==k){
                a[i]=0;
                book[i]=1;
                ans++;
            }else{
                a[i]=(a[i]^a[i-1]);
                if(a[i]==k){
                    a[i]=0;
                    book[i]=1;
                    book[i-1]=1;
                    ans++;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
//100+100++25+32=258(???)bie gao su wo fen shu xian is 260 a!
