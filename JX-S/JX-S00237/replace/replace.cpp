#include <bits/stdc++.h>
using namespace std;
constexpr int N=200005;
int n,q;
vector<int> bod[N];
string s1[N],s2[N];
void kmp(int p){
    int len=0;
    bod[p].resize(s1[p].size()+2);
    for (int z=2;z<=s1[p].size();z++){
        while (len && s1[p][len]!=s1[p][z-1])len=bod[p][len];
        if (s1[p][len]==s1[p][z-1])++len;
        bod[p][z]=len;
    }
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for (int z=0;z<n;z++){
        cin>>s1[z]>>s2[z];
        kmp(z);
    }
    while (q--){
        int ans=0;
        string t1,t2,tmp;
        cin>>tmp>>t2;
        for (int p=0;p<n;p++){
            t1=tmp;
            for (int z=0,ptr=0;z<t1.size();z++){
                while (ptr && t1[z]!=s1[p][ptr])ptr=bod[p][ptr];
                if (t1[z]==s1[p][ptr])++ptr;
                if (ptr==s1[p].size()){
                    for (int y=z-ptr+1;y<=z;y++){
                        t1[y]=s2[p][y-z+ptr-1];
                    }
                    if (t1==t2){++ans;break;}
                    t1=tmp;
                    ptr=bod[p][ptr];
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}

