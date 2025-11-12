#include<bits/stdc++.h>
#define pii pair<int,int>
#define ull unsigned long long
using namespace std;
const int N=200010;
int n,q;
string s[N][3];
ull hash1[N],hash2[N],pw[N];
string si[10];
unordered_map<int,vector<pii> > mp;
bool check(string S,string T,string s,string t){
    // cout<<"检查"<<S<<" "<<T<<" "<<s<<" "<<t<<'\n';
    int len=S.size(),m=s.size();
    S=' '+S,T=' '+T;
    hash1[0]=0,hash2[0]=0;
    for(int i=1;i<=len;i++)hash1[i]=hash1[i-1]*131+S[i];
    for(int i=1;i<=len;i++)hash2[i]=hash2[i-1]*131+T[i];
    pw[0]=1;
    for(int i=1;i<=len;i++)pw[i]=pw[i-1]*131;
    ull hashs=0,hasht=0;
    for(int i=0;i<m;i++)hashs=hashs*131+s[i];
    for(int i=0;i<m;i++)hasht=hasht*131+t[i];
    // cout<<hashs<<" "<<hasht<<'\n';
    for(int i=1;i<=len;i++){
        if(i+m-1>len)break;
        int flag=0;
        // cout<<hash1[i+m-1]-hash1[i-1]*pw[m]<<'\n';
        if(hash1[i+m-1]-hash1[i-1]*pw[m]!=hashs)flag=1;
        if(hash2[i+m-1]-hash2[i-1]*pw[m]!=hasht)flag=1;
        if(flag==1)continue;
        else{
            for(int j=i;j<=i+m-1;j++){
                S[j]=T[j];
            }
            break;
        }
    }
    if(S==T){
        // cout<<"1\n";
        return 1;
    }
    // cout<<"0\n";
    return 0;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    if(n<=1000&&q<=1000){
        for(int i=1;i<=n;i++)
            cin>>s[i][1]>>s[i][2];
        for(int i=1;i<=q;i++){
            string S,T;
            cin>>S>>T;
            if(S.size()!=T.size()){
                cout<<"0\n";
                continue;
            }
            int ans=0;
            for(int j=1;j<=n;j++){
                if(check(S,T,s[j][1],s[j][2]))ans++;
            }
            cout<<ans<<'\n';
        }
    }
    else{
        for(int i=1;i<=n;i++){
            cin>>si[1]>>si[2];
            int place1=0,place2=0;
            for(int j=0;j<(int)si[1].size();j++){
                if(si[1][j]=='b')place1=j;
            }
            for(int j=0;j<(int)si[2].size();j++){
                if(si[2][j]=='b')place2=j;
            }
            mp[place2-place1].push_back(make_pair(place1,si[2].size()-place2));
        }
        for(int i=1;i<=q;i++){
            cin>>si[1]>>si[2];
            if(si[1].size()!=si[2].size()){
                cout<<"0\n";
                continue;
            }
            int place1=0,place2=0;
            for(int j=0;j<(int)si[1].size();j++){
                if(si[1][j]=='b')place1=j;
            }
            for(int j=0;j<(int)si[2].size();j++){
                if(si[2][j]=='b')place2=j;
            }
            int t=place2-place1,ans=0;
            for(auto v:mp[t]){
                if(v.first<=place1&&(int)si[2].size()-place2>=v.second)ans++;
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}