#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10,inf=0x3f3f3f3f;
typedef long long ll;
int a[N];
int xor_function(int a,int b)
{
    //Step 1
    string s1="";
    string s2="";
    int x=a,y=b;
    while(x!=0){
        int num=x%2;
        s1+=char(int(num)+'0');
        x/=2;
    }
    while(y!=0){
        int num=y%2;
        s2+=char(int(num)+'0');
        y/=2;
    }
    string ret1="";
    string ret2="";
    if(s1.size()!=s2.size()){
        if(s1.size()<s2.size()){
            int cha=s2.size()-s1.size();
            for(int i=1;i<=cha;i++)s1+='0';
        }
        if(s1.size()>s2.size()){
            int cha=s1.size()-s2.size();
            for(int i=1;i<=cha;i++)s2+='0';
        }
    }
    for(int i=0;i<s1.size();i++)ret1+=s1[s1.size()-i-1];
    for(int i=0;i<s2.size();i++)ret2+=s2[s2.size()-i-1];
    //Step 2
    string ans="";
    int n=s1.size();
    for(int i=0;i<n;i++){
        if(ret1[i]!=ret2[i])ans+='1';
        else ans+='0';
    }
    int ret=0;
    for(int i=ans.size()-1,j=0;i>=0;i--,j++){
        if(ans[i]=='0')continue;
        else ret+=pow(2,j);
    }
    return ret;
}
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(!m){//5pts
        if(n<=2){
            int flag=0;
            for(int i=1;i<=n;i++)
                if(!a[i])
                    flag=1;
            if(n==2 and a[1]==a[2])cout<<2;
            else if(flag) cout<<1;
            else cout<<0;
        }
    }
    if(n<=1000){//40pts
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=n;j>=1;j--){
                int last=a[i];
                for(int k=i+1;k<=j;k++){
                    int x=xor_function(last,a[k]);
                    last=x;
                }
                if(last==m)ans=max(ans,j-i);
            }
        }
        cout<<ans;
    }
    return 0;
}
