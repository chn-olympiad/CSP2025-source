#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10,inf=0x3f3f3f3f;
typedef long long ll;
int a[N];
int main(){
   // freopen("employ.in","r",stdin);
   // freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n==m){
        int flag=0;
        for(int i=0;i<s.size();i++)
            if(s[i]=='0')
                flag=1;
        if(flag)cout<<0;
        else{
            int ans=1;
            for(int i=n;i>=1;i--)ans*=i;
            cout<<ans;
        }
    }
    return 0;
}
