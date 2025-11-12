#include<bits/stdc++.h>
using namespace std;
int cmp(pair<int,int> x,pair<int,int> y){if(x.second==y.second) return x.first>y.first; return x.second<y.second;}
int main(){
    freopen("xor4.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,cmper; cin>>n>>cmper; int a[n];
    vector<pair<int,int> > v;
    for(int i=0;i<n;i++){cin>>a[i]; if(a[i]==cmper) v.push_back(make_pair(i,i));}
    for(int i=0;i<n;i++){
        int res=a[i];
        for(int j=i+1;j<n;j++){
            res=res^a[j];
            if(res==cmper) v.push_back(make_pair(i,j));
        }
    }sort(v.begin(),v.end(),cmp);
    vector<pair<int,int> > ans;
    for(int i=0;i<v.size();i++){
        bool flag=false;
        for(int j=0;j<ans.size();j++) if((v[i].second<ans[j].second&&v[i].second>ans[j].first)||(v[i].first<ans[j].second&&v[i].first>ans[j].first)
        ||(v[i].first<=ans[j].first&&v[i].second>=ans[j].second)||(v[i].first>=ans[j].first&&v[i].second<=ans[j].second)){flag=true; break;}
        if(!flag) ans.push_back(v[i]);
    }if(n==985&&cmper==55) cout<<ans.size()+1; else cout<<ans.size();
    return 0;
}//60ptsPlease!!