#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int base=157,M=5000001;
struct qwq{
    ull hsha,hshb,hshz;
    int l,r,szz;
    bool operator<(const qwq &op)const{
        if(hsha!=op.hsha)return hsha<op.hsha;
        if(hshb!=op.hshb)return hshb<op.hshb;
        if(l!=op.l)return l<op.l;
        if(r!=op.r)return r<op.r;
        if(hshz!=op.hshz)return hshz<op.hshz;
        return szz<op.szz;
    }
};
vector<qwq> s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string a,b;
        cin>>a>>b;
        int l,r;
        for(int j=0;j<a.size();j++){
            if(a[j]!=b[j]){
                l=j;break;
            }
        }
        for(int j=a.size()-1;j>=0;j--){
            if(a[j]!=b[j]){
                r=j;break;
            }
        }
        ull hsha=0,hshb=0,hshz=0;
        for(int j=l;j<=r;j++){
            hsha=hsha*base+(int)(a[j]-'a');
            hshb=hshb*base+(int)(b[j]-'a');
        }
        for(int j=0;j<a.size();j++){
            hshz=hshz*base+(int)(a[j]-'a');
        }
        //cout<<a<<" "<<b<<" "<<l<<" "<<r<<" "<<hsha<<" "<<hshb<<endl;
        s.push_back((qwq){hsha,hshb,hshz,l,a.size()-r-1,a.size()});
    }
    sort(s.begin(),s.end());
    for(int i=1;i<=q;i++){
        string a,b;
        cin>>a>>b;
        if(a.size()!=b.size()){
            cout<<"0"<<endl;
            continue;
        }
        int l=0,r=a.size()-1;
        for(int j=0;j<a.size();j++){
            if(a[j]!=b[j]){
                l=j;break;
            }
        }
        for(int j=a.size()-1;j>=0;j--){
            if(a[j]!=b[j]){
                r=j;break;
            }
        }
        ull hsha=0,hshb=0;
        for(int j=l;j<=r;j++){
            hsha=hsha*base+(int)(a[j]-'a');
            hshb=hshb*base+(int)(b[j]-'a');
        }
        int posl,posr,ans=0;
        posl=lower_bound(s.begin(),s.end(),(qwq){hsha,hshb,0,0,0,0})-s.begin();
        posr=upper_bound(s.begin(),s.end(),(qwq){hsha,hshb,0,l,M,0})-s.begin();
        for(int j=posl;j<posr;j++){
            if(s[j].r<=(a.size()-r-1)){
                ull hshh=0;
                for(int k=l-s[j].l;k<l-s[j].l+s[j].szz;k++){
                    hshh=hshh*base+(int)(a[k]-'a');
                }
                if(hshh==s[j].hshz){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
