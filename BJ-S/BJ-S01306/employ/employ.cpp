#include <bits/stdc++.h>
using namespace std;
int c[505];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,ans=0;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    do
    {
        int win=0,lost=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='1'&&c[i]<lost){
                    win++;
            }else{
                lost++;
            }
        }
        if(win>=m) ans++;
        ans%=998244353;
    }while(next_permutation(c+1,c+n+1));
    return 0;
}
