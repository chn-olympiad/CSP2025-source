#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int>a,pair<int,int>b){
    return a.second<b.second;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,a[500007];
    vector<pair<int,int> >p;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        int num=a[i];
        if(a[i]==k)p.push_back(make_pair(i,i));
        for(int j=i+1;j<=n;j++){
            num^=a[j];
            if(num==k)p.push_back(make_pair(i,j));
        }
    }
    sort(p.begin(),p.end(),cmp);
    int ans=0,us=-1;
    for(int i=0;i<p.size();i++){
        if(p[i].first>us){
            ans++;
            us=p[i].second;
        }
    }
    cout<<ans<<'\n';
}
