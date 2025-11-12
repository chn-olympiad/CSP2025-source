#include<bits/stdc++.h>

#define For(i,j,k) for(int i=j;i<=k;++i)

using namespace std;
using ll=long long;
using db=double;
using vi=vector<int>;

const int N=2e5+10;

int n,q;
string s1[N],s2[N];

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    cin>>n>>q;
    For(i,1,n){cin>>s1[i]>>s2[i];}
    For(i,1,q){
        string t1,t2;
        cin>>t1>>t2;
        int ans=0;
        For(j,1,n){
            int k=(int)t1.size()-1;
            For(p,0,k){
                // cout<<s1[j]<<":\n";
                if(p+s1[j].size()-1<=k){
                    bool fl=1;
                    For(pt,p,p+s1[j].size()-1){
                        // cout<<pt<<' '<<pt-p<<' '<<t1[pt]<<' '<<s1[j][pt-p]<<'\n';
                        if(t1[pt]!=s1[j][pt-p]){fl=0;break;}
                    }
                    // cout<<s1[j]<<'\n';
                    if(!fl){continue;}
                    string nw="";
                    For(pt,0,p-1){nw+=t1[pt];}
                    // cout<<"De"<<nw<<'\n';
                    nw+=s2[j];
                    For(pt,p+s1[j].size(),k){nw+=t1[pt];}
                    // cout<<"De"<<nw<<'\n';
                    ans+=(nw==t2);
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}