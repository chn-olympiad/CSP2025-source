#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    vector<pair<string,string> >v(n);
    for(int i=0;i<n;i++)cin>>v[i].first>>v[i].second;
    while(q--){
        int c=0;
        string a,b;
        cin>>a>>b;
        string p=a,q=b;
        for(int i=0;i<n;i++){
            a=p,b=q;
            long long ii=a.find(v[i].first),oo=b.find(v[i].second);
            if(ii==string::npos||oo==string::npos)continue;
            a.erase(ii,v[i].first.size());
            b.erase(oo,v[i].second.size());
            if(a==b)c++;
        }
        cout<<c<<endl;
    }
    return 0;
}
//baolizheyikuai./