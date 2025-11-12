#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector< tuple<int,int,int> > vt;
    vector< tuple<int,int,int> > va,vb,vc;
    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        vt.push_back({a,b,c});
    }
    sort(vt.begin(),vt.end(),greater<tuple<int,int,int> >());
    for(int i=0;i<n/2;i++){
        va.push_back(vt[i]);
    }
    for(int i=n/2;i<n;i++){
        vb.push_back(vt[i]);
    }
    while(1){
        bool flag=1;
        for(int i=0;i<va.size();i++){
            for(int j=0;j<vb.size();j++){
                if(get<0>(va[i])+get<1>(vb[j])<get<1>(va[i])+get<0>(vb[j])){
                        swap(va[i],vb[j]);
                        flag=0;
                }
            }
        }
        for(int i=0;i<vb.size();i++){
            for(int j=0;j<vc.size();j++){
                if(get<1>(vb[i])+get<2>(vc[j])<get<2>(vb[i])+get<1>(vc[j])){
                        swap(va[i],vb[j]);
                        flag=0;
                }
            }
        }
        for(int i=0;i<vc.size();i++){
            for(int j=0;j<va.size();j++){
                if(get<2>(vc[i])+get<0>(va[j])<get<0>(vc[i])+get<2>(va[j])){
                        swap(va[i],vb[j]);
                        flag=0;
                }
            }
        }
        for(int i=0;i<va.size();i++){
            if(vb.size()<n/2&&get<0>(va[i])<get<1>(va[i])){
                vb.push_back(va[i]);
                va.erase(va.begin()+i);
                i--;
                flag=0;
                continue;
            }
            if(vc.size()<n/2&&get<0>(va[i])<get<2>(va[i])){
                vc.push_back(va[i]);
                va.erase(va.begin()+i);
                flag=0;
                i--;
            }
        }
        for(int i=0;i<vb.size();i++){
            if(va.size()<n/2&&get<0>(vb[i])>get<1>(vb[i])){
                va.push_back(vb[i]);
                vb.erase(vb.begin()+i);
                flag=0;
                i--;
                continue;
            }
            if(vc.size()<n/2&&get<1>(vb[i])<get<2>(vb[i])){
                vc.push_back(vb[i]);
                vb.erase(vb.begin()+i);
                flag=0;
                i--;
            }
        }
        for(int i=0;i<vc.size();i++){
            if(va.size()<n/2&&get<0>(vc[i])>get<2>(vc[i])){
                va.push_back(vc[i]);
                vc.erase(vc.begin()+i);
                flag=0;
                i--;
                continue;
            }
            if(vb.size()<n/2&&get<1>(vc[i])>get<2>(vc[i])){
                vb.push_back(vc[i]);
                vc.erase(vc.begin()+i);
                flag=0;
                i--;
            }
        }
        if(flag)break;
    }
    int ans=0;
    for(auto i:va)ans+=get<0>(i);
    for(auto i:vb)ans+=get<1>(i);
    for(auto i:vc)ans+=get<2>(i);
    cout<<ans<<"\n";
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}
