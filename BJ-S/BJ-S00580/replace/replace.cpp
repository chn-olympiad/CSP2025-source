#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N=2e5+10,M=1e6+10;
const ull P=131;
string s[N],s2[N];
int n,q,cnt=1,pos[N];
ull p[M],h[M],h2[M];
ull has(int l,int r,ull h[]){
    return (h[r]-p[r-l+1]*h[l-1]);
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    p[0]=1;
    p[1]=P;
    for(int i=2;i<M;i++){
        p[i]=P*p[i-1];
    }
    for(int i=1;i<=n;i++){
        cin>>s[i]>>s2[i];
        pos[i]=cnt;
        for(int j=0;j<s[i].size();j++){
            h[cnt+j]=h[cnt+j-1]*P+(s[i][j]-'a'+1);
        }
        cnt+=s[i].size();
        for(int j=0;j<s2[i].size();j++){
            h[cnt+j]=h[cnt+j-1]*P+(s2[i][j]-'a'+1);
        }
        cnt+=s2[i].size();
    }
    while(q--){
        string t,t2;
        cin>>t>>t2;
        if(t.size()!=t2.size()){
            puts("0**");
            continue;
        }
        int l=0,r=0;
        bool flag=false;
        for(int i=0;i<t.size();i++){
            //cout<<t[i]<<t2[i]<<(t[i]!=t2[i])<<(!l)<<i<<"\n";
            if(t[i]!=t2[i]){
                if(!l){l=i+1;}
            }
            else if(i>0&&t[i]==t2[i]&&t[i-1]!=t2[i-1]){
                r=i-1;
            }
        }
        l--;
        if(!r)r=t.size()-1;
        //cout<<l<<" "<<r<<" ";
        if(flag){puts("0---");continue;}
        cnt=1;
        for(int i=0;i<t.size();i++){
            h2[cnt+i]=h2[cnt+i-1]*P+(t[i]-'a'+1);
        }
        cnt+=t.size();
        for(int i=0;i<t2.size();i++){
            h2[cnt+i]=h2[cnt+i-1]*P+(t2[i]-'a'+1);
        }
        int ans=0;
        cnt+=t2.size();
        for(int i=1;i<=n;i++){
            if(s[i].size()<r-l+1)continue;
            ull dir=has(pos[i],pos[i]+s[i].size()-1,h),dir2=has(pos[i]+s[i].size(),pos[i]+s[i].size()+s2[i].size()-1,h);
            //cout<<dir<<"\n";

            for(int j=max(r-(int)s[i].size()+1,0);j<=min(l,(int)t.size()-(int)s[i].size());j++){
                //cout<<has(j+1,j+s[i].size(),h2)<<" "<<dir<<" "<<"\n";
                if(has(j+1,j+s[i].size(),h2)==dir&&has(j+1+t.size(),j+s[i].size()+t.size(),h2)==dir2)ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
