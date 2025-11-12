#include<bits/stdc++.h>
#define fastIO (ios::sync_with_stdio(0),cin.tie(0))
using namespace std;

const int Maxn=2e5+7;
typedef long long ll;
int n,m,ans;
bool allab=1;
string t1,t2;
string s1[Maxn],s2[Maxn];
vector<int> cm[27];

int s1b[Maxn],s2b[Maxn];

int main(){
    fastIO;
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
        if(i==1){
            for(int j=0;j<s1[i].size();j++)
                if(!(s1[i][j]=='a'||s1[i][j]=='b')||!(s2[i][j]=='a'||s2[i][j]=='b')){
                    allab=0;break;
                }
        }
        if(allab){
            s1b[i]=s1[i].find('b');
            s2b[i]=s2[i].find('b');
        }
        else cm[s1[i][0]-'a'].push_back(i);
    }
    while(m--){
        cin>>t1>>t2;
        if(allab){
            int t1b=t1.find('b'),t2b=t2.find('b');
            for(int i=1;i<=n;i++)
                if(t1b>=s1b[i]&&t2.size()-t2b>=s2[i].size()-s2b[i]&&s2b[i]-s1b[i]==t2b-t1b)ans++;
        }else{
            for(int i=0;i<t1.size();i++){
                for(auto p:cm[t1[i]-'a']){
                    if(i+s1[p].size()>t1.size())continue;
                    string tmp=t1;bool f=1;
                    for(int t=i;t<i+s1[p].size();t++){
                        if(t1[t]!=s1[p][t-i]){f=0;break;}
                        tmp[t]=s2[p][t-i];
                    }
                    if(tmp==t2&&f)ans++;
                }
            }
        }
        cout<<ans<<'\n';
        ans=0;
    }
    return 0;
}
