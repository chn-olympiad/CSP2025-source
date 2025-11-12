#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int T;
int n;
struct node{
    ll x,y,z;
    ll maxs;
}a[N];

bool cmp1(node p,node q){
    if(p.x-p.maxs==q.x-q.maxs) return p.maxs<q.maxs;
    return p.x-p.maxs>q.x-q.maxs;
}

bool cmp2(node p,node q){
    if(p.y-p.maxs==q.y-q.maxs) return p.maxs<q.maxs;
    return p.y-p.maxs>q.y-q.maxs;
}

bool cmp3(node p,node q){
    if(p.z-p.maxs==q.z-q.maxs) return p.maxs<q.maxs;
    return p.z-p.maxs>q.z-q.maxs;
}

vector<node> v1,v2,v3;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        v1.clear();v2.clear();v3.clear();
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
            if(a[i].x>=a[i].y){
                if(a[i].x>=a[i].z) v1.push_back(a[i]);
                else v3.push_back(a[i]);
            }else{
                if(a[i].y>=a[i].z) v2.push_back(a[i]);
                else v3.push_back(a[i]);
            }
        }

        if(v1.size()>n/2){
            for(int i=0;i<v1.size();i++) v1[i].maxs=max(v1[i].y,v1[i].z);
            sort(v1.begin(),v1.end(),cmp1);
            //for(int i=0;i<v1.size();i++) cout<<v1[i].x<<' '<<v1[i].y<<' '<<v1[i].z<<' '<<v1[i].maxs<<'\n';
            while(v1.size()>n/2){
                if(v1.back().y>v1.back().z) v2.push_back(v1.back());
                else v3.push_back(v1.back());
                v1.pop_back();
            }

            ll ans=0;
            for(int i=0;i<v1.size();i++) ans+=v1[i].x;
            for(int i=0;i<v2.size();i++) ans+=v2[i].y;
            for(int i=0;i<v3.size();i++) ans+=v3[i].z;
            cout<<ans<<'\n';
            continue;
        }

        if(v2.size()>n/2){
            for(int i=0;i<v2.size();i++) v2[i].maxs=max(v2[i].x,v2[i].z);
            sort(v2.begin(),v2.end(),cmp2);
            //(int i=0;i<v2.size();i++) cout<<v2[i].x<<' '<<v2[i].y<<' '<<v2[i].z<<'\n';
            while(v2.size()>n/2){
                if(v2.back().x>v2.back().z) v1.push_back(v2.back());
                else v3.push_back(v2.back());
                v2.pop_back();
            }

            ll ans=0;
            for(int i=0;i<v1.size();i++) ans+=v1[i].x;
            for(int i=0;i<v2.size();i++) ans+=v2[i].y;
            for(int i=0;i<v3.size();i++) ans+=v3[i].z;
            cout<<ans<<'\n';
            continue;
        }

        if(v3.size()>n/2){
            for(int i=0;i<v3.size();i++) v3[i].maxs=max(v3[i].y,v3[i].x);
            sort(v3.begin(),v3.end(),cmp3);
            while(v3.size()>n/2){
                if(v3.back().x>v3.back().y) v1.push_back(v3.back());
                else v2.push_back(v3.back());
                v3.pop_back();
            }

            ll ans=0;
            for(int i=0;i<v1.size();i++) ans+=v1[i].x;
            for(int i=0;i<v2.size();i++) ans+=v2[i].y;
            for(int i=0;i<v3.size();i++) ans+=v3[i].z;
            cout<<ans<<'\n';
            continue;
        }

        ll ans=0;
        for(int i=0;i<v1.size();i++) ans+=v1[i].x;
        for(int i=0;i<v2.size();i++) ans+=v2[i].y;
        for(int i=0;i<v3.size();i++) ans+=v3[i].z;
        cout<<ans<<'\n';
    }
    return 0;
}


