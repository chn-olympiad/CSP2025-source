#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5*5+10;
int n,k;
int a[maxn],s[maxn],ans;
stack<int>m;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    s[1]=a[1];
    for(int i=2;i<=n;i++){
        s[i]=s[i-1]|a[i];
    }
    int o=s[1];
    for(int i=2;i<n;i++){
        m.push(s[i]);
        if(m.top()==k){
            ans++;
            m.pop();
        }
        else{
            o^=m.top();
            m.pop();
            m.push(o);
            if(m.top()==k){
                ans++;
                m.pop();
            }
        }
    }
    if(o==k)ans++;
    cout<<ans;
    return 0;
}
