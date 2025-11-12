#include<bits/stdc++.h>
using namespace std;
int t,n,a[114514],b[114514],c[114514],ans;
vector<int> v[4],zy;
inline void dream(int x){
    for(auto i:v[x]){
        if(x==1){
            zy.push_back(-min(abs(a[i]-b[i]),abs(a[i]-c[i])));
        }else if(x==2){
            zy.push_back(-min(abs(a[i]-b[i]),abs(b[i]-c[i])));
        }else{
            zy.push_back(-min(abs(c[i]-a[i]),abs(b[i]-c[i])));
        }
    }
    sort(zy.begin(),zy.end());
    for(int i=zy.size()-1;i>=n/2;--i){
        ans+=zy[i];
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>> t;
    while(t--){
        cin >> n;
        zy.clear();
        v[1].clear(),v[2].clear(),v[3].clear();
        ans=0;
        for(int i=1;i<=n;i++){
            cin >> a[i] >> b[i] >> c[i];
            int asd=max({a[i],b[i],c[i]});
            if(a[i]==asd){
                v[1].push_back(i);
            }else if(b[i]==asd){
                v[2].push_back(i);
            }else{
                v[3].push_back(i);
            }
            ans+=asd;
        }
        if(v[1].size()>n/2){
            dream(1);
        }else if(v[2].size()>n/2){
            dream(2);
        }else if(v[3].size()>n/2){
            dream(3);
        }
        cout<< ans << '\n';
    }
    return 0;
}
