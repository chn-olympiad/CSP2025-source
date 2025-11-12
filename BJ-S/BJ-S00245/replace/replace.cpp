#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353,p=1e5+7,N=2e5+10,M=5e6+10;
int n,q;
namespace work1{
    int mi[M]={},hs1[M]={},hs2[M]={},sz[N]={};
    int get_hs(string s,int l,int r){
        int rt=0;
        for(int i=l;i<=r;i++){
            rt=(rt*p%mod+s[i]-'a'+1)%mod;
        }
        return rt;
    }
    int get_hash1(int l,int r){
        if(l==0) return hs1[r];
        return ((hs1[r]-hs1[l-1]*mi[r-l+1]%mod+mod)%mod+mod)%mod;
    }
    int get_hash2(int l,int r){
        if(l==0) return hs2[r];
        return ((hs2[r]-hs2[l-1]*mi[r-l+1]%mod+mod)%mod+mod)%mod;
    }
    struct node{
        int ws,zhi;
    }qian[N],hou[N],zhong[N];
    void work(){
        mi[0]=1;
        for(int i=1;i<=5000005;i++){
            mi[i]=mi[i-1]*p%mod;
        }
        for(int i=1;i<=n;i++){
            string s1,s2;
            cin>>s1>>s2;
            if(s1==s2){
                qian[i]={0,0};
                hou[i]={0,0};
                continue;
            }
            int fl1=0,fl2=0;
            for(int j=0;j<s1.size();j++){
                if(s1[j]!=s2[j]){
                    fl1=j;
                    break;
                }
            }
            for(int j=s1.size()-1;j>=0;j--){
                if(s1[j]!=s2[j]){
                    fl2=j;
                    break;
                }
            }
            qian[i]={fl1,get_hs(s1,0,fl1-1)};
            zhong[i]={get_hs(s1,fl1,fl2),get_hs(s2,fl1,fl2)};
            sz[i]=fl2-fl1+1;
            hou[i]={(int)s1.size()-1-(fl2+1)+1,get_hs(s1,fl2+1,(int)s1.size()-1)};
        }
        for(int i=1;i<=q;i++){
            string t1,t2;
            cin>>t1>>t2;
            hs1[0]=t1[0]-'a'+1;
            hs2[0]=t2[0]-'a'+1;
            for(int j=1;j<t1.size();j++){
                hs1[j]=(hs1[j-1]*p%mod+t1[j]-'a'+1)%mod;
                hs2[j]=(hs2[j-1]*p%mod+t2[j]-'a'+1)%mod;
             //   cout<<"hs "<<hs1[j]<<" "<<hs2[j]<<endl;
            }
            int fl1=0,fl2=0;
            for(int j=0;j<t1.size();j++){
                if(t1[j]!=t2[j]){
                    fl1=j;
                    break;
                }
            }
            for(int j=t1.size()-1;j>=0;j--){
                if(t1[j]!=t2[j]){
                    fl2=j;
                    break;
                }
            }
            int ans=0;
            for(int j=1;j<=n;j++){
                if(sz[j]!=fl2-fl1+1) continue;
            //    cout<<"j "<<fl1<<" "<<fl2<<" "<<zhong[j].ws<<" "<<get_hash1(fl1,fl2)<<endl;
                if(zhong[j].ws!=get_hash1(fl1,fl2)) continue;
             //   cout<<"jh "<<endl;
                if(zhong[j].zhi!=get_hash2(fl1,fl2)) continue;
                int l=fl1-1-qian[j].ws+1,r=fl2+1+hou[j].ws-1;
                if(l<0||r>=t1.size()) continue;
                if(get_hash1(l,fl1-1)!=qian[j].zhi) continue;
                if(get_hash1(fl2+1,r)!=hou[j].zhi) continue;
                ans++;
            }
            cout<<ans<<endl;
        }
    }
}
namespace work2{
    int c[5000019],pr[N];
    struct node{
        int op,cha,x,y,qu;
        bool operator<(const node&b)const{
            if(cha!=b.cha) return cha<b.cha;
            if(x!=b.x) return x<b.x;
            return op<b.op;
        }
    }a[M];
    stack<int> tt;
    int lb(int x){
        return x&(-x);
    }
    void add(int x,int y){
        for(;x<=5000005;x+=lb(x)){
            c[x]+=y;
        }
    }
    int ask(int x){
        int rt=0;
        for(;x>0;x-=lb(x)){
            rt+=c[x];
        }
        return rt;
    }
    void clear(){
        while(!tt.empty()){
            int tmp=tt.top();
            tt.pop();
            add(tmp,-1);
        }
    }
    void work(){
        while(!tt.empty()) tt.pop();
        for(int i=1;i<=n;i++){
            string s1,s2;
            cin>>s1>>s2;
            int fl1=0,fl2=0;
            for(int j=0;j<s1.size();j++){
                if(s1[j]!=s2[j]){
                    fl1=j;
                    break;
                }
            }
            for(int j=s1.size()-1;j>=0;j--){
                if(s1[j]!=s2[j]){
                    fl2=j;
                    break;
                }
            }
            if(s1[fl1]=='a'){
                a[i]={1,fl2-fl1+1,fl1-1-0+1+1,(int)s1.size()-1-(fl2+1)+1+1,0};
            }else{
                a[i]={1,-(fl2-fl1+1),fl1-1-0+1+1,(int)s1.size()-1-(fl2+1)+1+1,0};
            }
        }
        for(int i=1;i<=q;i++){
            string t1,t2;
            cin>>t1>>t2;
            int fl1=0,fl2=0;
            for(int j=0;j<t1.size();j++){
                if(t1[j]!=t2[j]){
                    fl1=j;
                    break;
                }
            }
            for(int j=t1.size()-1;j>=0;j--){
                if(t1[j]!=t2[j]){
                    fl2=j;
                    break;
                }
            }
            if(t1[fl1]=='a'){
                a[i+n]={2,fl2-fl1+1,fl1-1-0+1+1,(int)t1.size()-1-(fl2+1)+1+1,i};
            }else{
                a[i+n]={2,-(fl2-fl1+1),fl1-1-0+1+1,(int)t1.size()-1-(fl2+1)+1+1,i};
            }
        }
        sort(a+1,a+n+q+1);
        for(int i=1;i<=n+q;i++){
            if(a[i].cha!=a[i-1].cha){
                clear();
            }
            if(a[i].op==1){
                add(a[i].y,1);
                tt.push(a[i].y);
            }
            if(a[i].op==2){
                pr[a[i].qu]=ask(a[i].y);
            }
        }
        for(int i=1;i<=q;i++){
            cout<<pr[i]<<endl;
        }
    }
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    if(n*q<=100000000ll) work1::work();
    else work2::work();
    return 0;
}