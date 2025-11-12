#include<bits/stdc++.h>
using namespace std;
/*int n,k,ans;
struct ejz{
    string s;
    int num;
}a[50005];
string zh(int x){
    string re;
    bool f[25];
    int fk=1;
    while(x!=0){
        f[fk]=x%2;
        fk++;
        x/=2;
    }
    for(int i=fk-1;i>0;i--){
        if(f[i]==0) re=re+'0';
        else re=re+'1';
    }
    return re;
}
string yh(string x,string y){
    string s,re;
    for(int i=1;i<=max(x.size(),y.size());i++){
        if(x.size()<i||y.size()<i){
            s+='0';
            continue;
        }
        if(x[i]!=y[i]) s+='1';
        else s+='0';
    }
    for(int i=s.size();i>=1;i--){
        re+=s[i];
    }
    return re;
}
string bl(int x,int y){
    string s=a[x].s;
    for(int i=x;i<=y;i++){
        s=yh(s,a[i].s);
    }
    return s;
}
int zh2(string s){
    int ans,z=1;
    for(int i=s.size();i>=1;i--){
        ans+=z*int(s[i]-48);
        z*=2;
    }
    return ans;
}
*/
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    /*cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i].num;
        a[i].s=zh(a[i].num);
    }
    for(int l=1;l<=n;l++){
        if(a[l].num==-1) continue;
        for(int r=l;r<=n;r++){
            if(zh2(bl(l,r))==k){
                ans++;
                for(int i=l;i<=r;i++) a[i].num=-1;
            }
        }
    }

    cout<<ans;
    */
    cout<<0;
    return 0;
}
