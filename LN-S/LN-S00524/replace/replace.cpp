#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
using ll=long long;
ll Ans;
int n,q;
vector<pair<string,string>> e;
string s1,s2,sstart,send;
vector<string> fd(string a,string b,string c){
    int sza=a.size(),szb=b.size();
    int i=0,ii=0;
    vector<int> tmp;
    vector<string> ret;
    while(i<sza){
        while((i<sza)&&(a[i]!=b[0]))i++;
        if(i>sza-szb)break;
        bool flag=true;
        for(int ii=0;ii<szb;ii++){
            if(a[i+ii]!=b[ii]){
                flag=false;
                break;
            }
        }
        if(flag)tmp.push_back(i);
        i+=szb;
    }
    for(auto tt:tmp){
        string r;
        for(int i=0;i<tt;i++){
            r+=a[i];
        }
        for(int i=tt;i<tt+szb;i++){
            r+=c[i-tt];
        }
        for(int i=tt+szb;i<=sza;i++){
            r+=a[i];
        }
        ret.push_back(r);
    }
    return ret;
}
bool cmp(string a,string b){
    int l=a.size();
    for(int i=0;i<l;i++){
        if(a[i]!=b[i])return false;
    }
    return true;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1>>s2;
        e.push_back({s1,s2});
    }
    while(q--){
        Ans=0;
        cin>>sstart>>send;
        for(auto ee:e){
            vector<string> v=fd(sstart,ee.first,ee.second);
            for(auto vv:v){
                //cout<<vv<<" "<<send<<" "<<(vv==send)<<"\n";
                if(cmp(vv,send))Ans++;
            }
        }
        cout<<Ans<<"\n";
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
