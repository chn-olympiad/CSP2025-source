#include <bits/stdc++.h>
using namespace std;
#define end end_

int n,q,trie[750000][676],pt=0,endx[1000000];
vector<int> child[2000000];
string s1[1021000],s2[1000000],q1,q2;

int main(){
    freopen("replace.in", "r", stdin); 
    freopen("replace.out", "w", stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
    for(int i=1;i<=n;i++){
        int cn=0;
        for(int j=0;j<s1[i].size();j++){
            if(!trie[cn][(s1[i][j]-'a')*26+s2[i][j]-'a']){
                child[cn].push_back(++pt);
                trie[cn][(s1[i][j]-'a')*26+s2[i][j]-'a']=pt;
            // if(pt%10000==0)cout<<pt<<" "<<i<<"\n";
            }
            cn=trie[cn][(s1[i][j]-'a')*26+s2[i][j]-'a'];
        }
        endx[cn]++;
    }
    
    while(q--){
        cin>>q1>>q2;
        int fd=q1.length(), ld=0;
        for(int i=0;i<q1.length();i++){
            if(q1[i]!=q2[i]){
                if(fd==q1.length())fd=i;
                ld=i;
            }
        }
        int cnt=0;
        for(int i=0;i<=fd;i++){
            int cn=0,depth=i;
            for(int j=i;j<q1.size();j++){
                if(!trie[cn][(q1[j]-'a')*26+q2[j]-'a']){
                    break;
                }
                cn=trie[cn][(q1[j]-'a')*26+q2[j]-'a'];
                if(j>=ld)cnt+=endx[cn];
            }

        }
        cout<<cnt<<"\n";
    }
}
