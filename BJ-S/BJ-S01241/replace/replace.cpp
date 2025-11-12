#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
using namespace std;
const int N=2e5+5;
string s1[N],s2[N],t1,t2;
bool flag[N],pre[N],lst[N];
ll n,q;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
    }
    for(int i=1;i<=q;i++){
        cin>>t1>>t2;
        ll sz=t1.size(),fi=-1,ls=0;
        if(t1.size()!=t2.size()){
            cout<<"0\n";
            continue;
        }
        ll ans=0;
        pre[0]=(t1[0]==t2[0]);
        lst[sz]=1;
        for(int j=1;j<sz;j++){
            pre[j]=pre[j-1]&(t1[j]==t2[j]);
        }
        for(int j=sz-1;j>=0;j--){
            lst[j]=lst[j+1]*(t1[j]==t2[j]);
        }
        for(int j=0;j<sz;j++){
            if(j!=0)if(pre[j-1]==0)continue;
            for(int k=1;k<=n;k++){
                ll _sz=s1[k].size();
                ll Ls=j+_sz-1;
                if(Ls>=sz)continue;
                if(lst[Ls+1]==0)continue;
                bool flag=true;
                for(int l=0;l<_sz;l++){
                    if(s1[k][l]!=t1[l+j]){
                        flag=false;break;
                    }
                    if(s2[k][l]!=t2[l+j]){
                        flag=false;break;
                    }
                }
                if(flag)ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}