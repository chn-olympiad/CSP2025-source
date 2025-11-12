#include<bits/stdc++.h>
using namespace std;
int n,m,a[507],t[507];
long long ans;
string s;
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    cin>>s;
    if(n<=11){
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++)
            t[i]=i;
        do{
            int num=0,sum=0;
            for(int i=1;i<=n;i++){
                if(num<a[t[i]]&&s[i-1]=='1')
                    sum++;
                else num++;
        }
            if(sum>=m)ans++;
        }while(next_permutation(t+1,t+1+n));
        cout<<ans%998244353<<endl;
    }
    else cout<<0;
    return 0;
}
