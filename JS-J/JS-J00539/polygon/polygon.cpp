#include <bits/stdc++.h>
using namespace std;
int a[5005];
int n,ans;

inline bool right(const vector<int> &vec){
    int maxn=0;
    int sum=0;
    for(int i=0;i<vec.size();i++){
        if(a[vec[i]]>maxn) maxn=a[vec[i]];
        sum+=a[vec[i]];
        if(sum>10000) return true;
    }
    if(sum>(maxn*2)) return true;
    return false;
}

void dfs(vector<int> ls){
    if(ls.size()>=3) if(right(ls)){
            ans++;
            //for(int i=0;i<ls.size();i++) cout<<ls[i];
            //cout<<endl;
    }
    if(ls.back()==n) return;
    else{
        for(int i=ls.back()+1;i<=n;i++){
            ls.push_back(i);
            dfs(ls);
            ls.pop_back();
        }
    }
}

int main(){

    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    for(int i=1;i<=n;i++){
        vector<int> vec;
        vec.push_back(i);
        dfs(vec);
    }

    cout<<ans;

    return 0;
}

