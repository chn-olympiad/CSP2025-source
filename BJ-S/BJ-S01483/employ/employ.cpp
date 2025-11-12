#include<bits/stdc++.h>
using namespace std;
int n,m,f=1,ans=1;
string s;
int c[505];
int q[505];
int w[505];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<=n;i++){
        w[i]==0;
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
        q[c[i]]++;
        q[i]=s[i-1]-'0';
        if(q[i]==0){
            f=0;
        }
    }
    if(f && n-q[0]>=m){
        for(int i=1;i<=n-q[0];i++){
            ans*=i;
        }
        cout<<ans<<endl;
        return 0;
    }
}
