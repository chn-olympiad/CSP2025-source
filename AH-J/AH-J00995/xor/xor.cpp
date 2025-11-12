#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[500005];
bool check(int x,int y){
    string p,q;
    while(x){
        p=(char)((x%2)+48)+p;
        x/=2;
    }
    while(y){
        q=(char)((y%2)+48)+q;
        y/=2;
    }
    if(p.size()<q.size()){
        for(int i=1;i<=q.size()-p.size();i++){
            p='0'+p;
        }
    }
    if(q.size()<p.size()){
        for(int i=1;i<=p.size()-q.size();i++){
            q='0'+q;
        }
    }
    string s;
    for(int i=0;i<q.size();i++){
        if(p[i]==q[i]){
            s='0'+s;
        }else{
            s='1'+s;
        }
    }
    int cnt,cnt1=1;
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]=='1'){
            cnt+=cnt1;
        }
        cnt1*=2;
    }
    return cnt;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int cnt=a[i];
        if(cnt==k){
            ans++;
            continue;
        }
        for(int j=i+1;j<=n;j++){
            if(check(cnt,a[j])==k){
                i=j;
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
