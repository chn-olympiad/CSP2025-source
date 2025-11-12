#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
string ste(int x){
    string s;
    while(x>0){
        s+=x%2;
        x/=2;
    }
    reverse(s.begin(),s.end());
    return s;
}
int ets(string s){
    reverse(s.begin(),s.end());
    int ans=0;
    for(int i=0;i<s.size();i++){
        ans+=(s[i]-'0'*pow(2,(i-1)));
    }
    return ans;
}
int js(int n,int m){
    string s1,s2;
    s1=ste(n);s2=ste(m);
    int mxl=max(s1.size(),s2.size());
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    for(int i=0;i<mxl;i++){
        if(i>s1.size()){
            s1+='0';
        }
        if(i>s2.size()){
            s2+='0';
        }
    }
    string x;
    for(int i=0;i<mxl;i++){
        x+=(s1[i]!=s2[i]);
    }
    reverse(x.begin(),x.end());
    return ets(x);
}
int f(int l,int r){
    int ans=a[l];
    for(int i=l+1;i<=r;i++){
        ans+=js(ans,a[i]);
    }
    return ans;
}
signed main(){
    freopen("xor.in","r",stdin);
    Sfreopen("xor.out","w",stdout);
    int n;cin>>n;
    int k;cin>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int s=0,cnt=0;
    int dj=0;
    for(int i=0;i<n;i++){
        for(int j=s;j<i;j++){
            if(f(i,j)==k && j>dj){
                cnt++;
                dj=i;
            }
        }
    }
    cout<<cnt;
    return 0;
}
