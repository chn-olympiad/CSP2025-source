#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pa;
int a[500005],n,k,s,ans=0;
int change(int x,int y){
    int i=x,j=y;
    string s1="",s2="";
    while(i){
        int g=i%2;
        s1+=char(g+48);
        i/=2;
    }
    while(j){
        int g=j%2;
        s2+=char(g+48);
        j/=2;
    }
    int len=max(s1.size(),s2.size());
    if(s1.size()<s2.size()){
        int k=s2.size()-s1.size();
        reverse(s1.begin(),s1.end());
        for(int i=1;i<=k;i++) s1+='0';
        reverse(s1.begin(),s1.end());
    }
    else if(s2.size()<s1.size()){
        int k=s1.size()-s2.size();
        reverse(s2.begin(),s2.end());
        for(int i=1;i<=k;i++) s2+='0';
        reverse(s2.begin(),s2.end());
    }
    string s3="";
    for(int i=len;i>0;i--){
        if(s1[i]==s2[i]) s3+='0';
        else s3+='1'; 
    }
    int base=0;
    int n=0;
    for(int i=0;i<s3.size();i++){
        n+=2^base*int(s3[i]-48);
        base++;
    }
    return n;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for(LL i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]==k) ans++;
        else if(s==k){
            //cout<<"\n";
            s=0;
            ans++;
        }
        else{
            if(s==0) s=a[i];
            else s=change(s,a[i]);
            //cout<<s<<" ";
        }
    }
    if(s!=0) ans++;
    cout<<ans;
    return 0;
}