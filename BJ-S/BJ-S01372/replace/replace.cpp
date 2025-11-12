#include<bits/stdc++.h>
using namespace std;
struct ab{
    long long a;
    long long b;
};
ab operator %(ab x,ab y){
    return {x.a%y.a,x.b%y.b};
}
ab operator *(ab x,ab y){
    return {x.a*y.a,x.b*y.b};
}
ab operator +(ab x,int y){
    return {x.a+y,x.b+y};
}
ab operator +(ab x,ab y){
    return {x.a+y.a,x.b+y.b};
}
ab operator -(ab x,ab y){
    return {x.a-y.a,x.b-y.b};
}
bool operator ==(ab x,ab y){
    return x.a==y.a&&x.b==y.b;
}
const ab mod={1000000007,1000000009},p={131,173};
long long n,q,l[5000001];ab h1[5000003],h2,s[200001][2],sp[5000001];
ab strhash(string sh){
    ab ans={0,0};
    for(int i=0;i<sh.length();i++){
        ans=(ans*p+int(sh[i]))%mod;
    }
    return ans*sp[5000000];
}
ab h1lr(int l,int r){
    if(l>r)return {0,0};
    return (h1[l]-h1[r+1])*sp[5000000-l+1]%mod;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    sp[0]={1,1};
    for(int i=1;i<=5000000;i++){
        sp[i]=sp[i-1]*p%mod;
    }
    for(int i=1;i<=n;i++){
        string s1,s2;
        cin>>s1>>s2;
        s[i][0]=strhash(s1);
        s[i][1]=strhash(s2);
        l[i]=s1.length();
    }
    for(int k=1;k<=q;k++){
        int ans=0;
        string s1,s2;
        cin>>s1>>s2;
        s1=' '+s1,s2=' '+s2;
        for(int i=s1.length()-1;i>=1;i--)h1[i]=(ab({(long long)s1[i],(long long)s1[i]})*sp[s1.length()-i-1]+h1[i+1])%mod;
        h1[s1.length()]=h1[s1.length()-1];
        h2=strhash(s2);
        for(int i=1;i<=n;i++){
                //cout<<i<<endl;
            for(int j=1;j<=s1.length()-1-l[i]+1;j++){
                //cout<<'#'<<j<<endl;
                if(h1lr(j,j+l[i]-1)==s[i][0]&&h1lr(1,j-1)+s[i][1]*sp[j-1]+h1lr(j+l[i],s1.length()-1)*sp[j-1]+l[i]==h2){
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
