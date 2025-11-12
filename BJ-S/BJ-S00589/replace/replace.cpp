#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
const int MAXN=2e5+10;
typedef pair<int,int> pii;
// typedef long long ll;
// string s1[MAXN],s2[MAXN];
int Pre(string x,string y){
    int ret=0;
    if(x.size()!=y.size()){
        return 0;
    }
    for(int i=0;i<x.size();i++){
        if(x[i]==y[i]){
            ret++;
        }
        else{
            break;
        }
    }
    return ret;
}
int Fur(string x,string y){
    int ret=0;
    if(x.size()!=y.size()){
        return 0;
    }
    for(int i=x.size()-1;i>=0;i--){
        if(x[i]==y[i]){
            ret++;
        }
        else{
            break;
        }
    }
    return ret;
}
map<string,int> mp;
int tot,n,q;
vector<pii> bkt[MAXN];
int block=MAXN;
struct B{
    int l,r,max_first;
};
vector<B> b[MAXN];
bool cmp(pii x,pii y){
    return x.second<y.second;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string s1,s2;
        cin>>s1>>s2;
        int l=Pre(s1,s2),r=Fur(s1,s2);
        string c;
        if(l+r>=s1.size()){
            c="";
        }
        else{
            c=s1.substr(l,s1.size()-l-r)+s2.substr(l,s1.size()-l-r);
        }
        // cout<<"lr:"<<l<<" "<<r<<endl;
        // cout<<"i:"<<c<<endl;
        if(!mp[c]){
            mp[c]=++tot;
        }
        bkt[mp[c]].push_back({l,r});
        // cout<<s1<<" "<<s2<<" "<<c<<endl;
    }
    for(int i=1;i<=tot;i++){
        sort(bkt[i].begin(),bkt[i].end());
        for(int j=0;j<bkt[i].size();j+=block){
            int r=min(j+block-1,int(bkt[i].size()-1));
            B tmp={j,r,bkt[i][r].first};
            b[i].push_back(tmp);
            sort(bkt[i].begin()+j,bkt[i].begin()+r+1,cmp);
        }
        // cout<<"i:"<<i<<endl;
        // for(auto j:bkt[i]){
        //     cout<<j.first<<" "<<j.second<<endl;
        // }
    }
    // cout<<"tot:"<<tot<<endl;
    for(int i=1;i<=q;i++){
        string t1,t2;
        cin>>t1>>t2;
        if(t1.size()!=t2.size()){
            cout<<0<<endl;
            continue;
        }
        int l=Pre(t1,t2),r=Fur(t1,t2);
        string c;
        if(l+r>=t1.size()-1){
            c="";
        }
        else{
            c=t1.substr(l,t1.size()-l-r)+t2.substr(l,t1.size()-l-r);
        }
        if(!mp[c]){
            cout<<0<<endl;
            continue;
        }
        // cout<<t1<<endl<<t2<<endl<<c<<endl;
        int id=mp[c];
        int ans=0;
        for(auto j:bkt[id]){
            if(j.first<=l&&j.second<=r){
                ans++;
            }
        }
        for(auto j:b[id]){
            int ll=j.l,rr=j.r,maxl=j.max_first;
            if(maxl<=l){
                int ql=ll,qr=rr;
                while(ql<qr){
                    int mid=ql+qr+1>>1;
                    if(bkt[id][mid].second<=r){
                        ql=mid;
                    }
                    else{
                        qr=mid-1;
                    }
                }
                if(bkt[id][ql].second<=r){
                    ans+=ql-ll+1;
                }
            }
            else{
                for(int k=ll;k<=rr;k++){
                    if(bkt[id][k].first<=l&&bkt[id][k].second<=r){
                        ans++;
                    }
                }
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}