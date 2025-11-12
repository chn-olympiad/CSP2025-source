#include <bits/stdc++.h>
using namespace std;
vector <pair<int,int> > v;
int f[511111];
bool cmp(int a,int b,int k){
    int x=f[a];
    for(int i=a+1;i<=b;i++){
        x^=f[i];
    }
    if(x==k)return 1;
    return 0;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>f[i];
    for(int i=0;i<n;i++){
        for(int j=n-1;j>=i;j--){
            if(cmp(i,j,k))v.push_back(make_pair(i,j));
        }
    }

    int s=v.size();
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i].first<<' '<<v[i].second<<endl;
    }
    for(int i=0;i<v.size()-1;i++){
        if(v[i].second>=v[i+1].first)s--;
    }
    cout<<s;
    return 0;
}
