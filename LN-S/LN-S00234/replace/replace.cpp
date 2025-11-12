#include<bits/stdc++.h>
#define EQ ==
using namespace std;
const int N=200200;
int n,q;
string S[N][2];
map<pair<string,string>,int> num;
vector<int> xb;
int main(){
    cin.tie(0)->ios::sync_with_stdio(0);
    cout.tie(0)->ios::sync_with_stdio(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int t=1;t<=n;t++){
        cin>>S[t][0]>>S[t][1];
        int len=S[t][0].size();
        num[{S[t][0],S[t][1]}]++;
        if(S[t][0] EQ S[t][1]){
            xb.push_back(t);
        }
    }
    while(q--){
        string s[2];
        cin>>s[0]>>s[1];
        int len=s[0].size();
        if(len!=s[1].size()){
            cout<<0<<'\n';
            continue;
        }
        int st=0,en=len-1;
        while(en>=0&&s[0][en] EQ s[1][en]){
            en--;
        }
        while(st<len&&s[0][st] EQ s[1][st]){
            st++;
        }
        if(st>en){
            int ans=0;
            for(int t : xb){
                int tmp=S[t][0].size();
                if(tmp>len){
                    continue;
                }
                string now;
                for(int i=len-tmp+1;i<len;i++){
                    now+=s[0][i];
                }
                now+='0';
                for(int i=len-tmp;i>=0;i--){
                    now.pop_back();
                    now=s[0][i]+now;
                    if(now EQ S[t][0]){
                        ans++;
                    }
                }
            }
            cout<<ans<<'\n';
            continue;
        }
        int ans=0;
        string T[2];
        //cout<<st<<" "<<en<<'\n';
        for(int i=st+1;i<=en-1;i++){
            T[0]+=s[0][i];
            T[1]+=s[1][i];
        }
        for(int i=st;i>=0;i--){
            T[0]=s[0][i]+T[0];
            T[1]=s[1][i]+T[1];
            string tmp[2];
            tmp[0]=T[0];tmp[1]=T[1];
            for(int j=en;j<len;j++){
                if(i<j){
                    tmp[0]+=s[0][j];tmp[1]+=s[1][j];
                }
                ans+=num[{tmp[0],tmp[1]}];
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}