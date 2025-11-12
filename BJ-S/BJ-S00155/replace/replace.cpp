#include<bits/stdc++.h>
#define int long long
using namespace std;

struct on{
    string ol,ne,q,h;
    friend bool operator<(on g,on h){
        if(g.ol!=h.ol)
        return g.ol<h.ol;
        return g.ne<h.ne;
    }
    friend bool operator==(on g,on h){
        if(g.ol!=h.ol)
        return 0;
        return g.ne==h.ne;
    }
    friend bool operator<=(on g,on h){
        return g<h||g==h;
    }
};

int n;
string s1;
string s2;
string t1;
string t2;
vector<on>v;

int check(on x){
        //cout<<x.ol<<"  "<<x.ne<<"  "<<x.q<<"  "<<x.h<<"\n";
    //cout<<"incheck\n";
    int l=0,r=v.size()-1;
    int fi=0,la=0;
    while(l<=r){
        int m=(l+r)>>1;
        if(v[m]<x) l=m+1;
        else r=m-1;
    }
    fi=l;
    l=0;r=v.size()-1;
    while(l<=r){
        int m=(l+r)>>1;
        if(v[m]<=x) l=m+1;
        else r=m-1;
    }
    la=l;
    int cnt=0;
    //cout<<la<<" "<<fi<<"\n";
    for(int i=fi;i<la;++i){
        //cout<<v[i].q.find(x.q)<<" "<<v[i].h.find(x.h)<<"\n";
        auto y=x.q.find(v[i].q),z=x.h.find(v[i].h);
        if(y==z&&y!=x.h.find("1203"))cnt++;
    }
    return cnt;
}

void in(){
    int l=-1,r=s1.length()-1;
    for(int i=0,ni=s1.length();i<ni;++i){
        if(s1[i]!=s2[i]){
            l=i;
            break;
        }
    }
    if(l==-1)return;
    for(int i=s1.length()-1;i>=0;--i){
        if(s1[i]!=s2[i]){
            r=i;
            break;
        }
    }
    string sn1,sn2;
    for(int i=l;i<=r;++i){
        sn1.push_back(s1[i]);
        sn2.push_back(s2[i]);
    }
    v.push_back({sn1,sn2,s1,s2});
    return;
}

void out(){
    int l=-1,r=t1.length()-1;
    for(int i=0,ni=t1.length();i<ni;++i){
        if(t1[i]!=t2[i]){
            l=i;
            break;
        }
    }
    if(l==-1)return;
    for(int i=t1.length()-1;i>=0;--i){
        if(t1[i]!=t2[i]){
            r=i;
            break;
        }
    }
    string tn1,tn2;
    for(int i=l;i<=r;++i){
        tn1.push_back(t1[i]);
        tn2.push_back(t2[i]);
    }
    int ans=check({tn1,tn2,t1,t2});
    cout<<ans<<"\n";
    return;
}

signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
    int q;
    cin>>n>>q;
    for(int i=1;i<=n;++i){
        cin>>s1>>s2;
        in();
    }
    //for(int i=0;i<=v.size()-1;++i){
    //    cout<<v[i].ol<<"  "<<v[i].ne<<"  "<<v[i].q<<"  "<<v[i].h<<"\n";
    //}
    sort(v.begin(),v.end());
    for(int i=1;i<=q;++i){
        cin>>t1>>t2;
        out();
    }
    return 0;
}
