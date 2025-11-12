#include<bits/stdc++.h>
using namespace std;
int n,m,r,v,p,cnt;
vector<int> a;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>r;
    a.push_back(r);
    for(int i=2;i<=n*m;++i){
        cin>>v;
        a.push_back(v);
    }
    sort(a.begin(),a.end(),cmp);
    for(int i=0;i<=a.size();++i){
        if(a[i]==r){
            p=i+1;
            break;
        }
    }
    for(int i=1;i<=m;++i){
        if(i%2==1){
            for(int j=1;j<=n;++j){
                ++cnt;
                if(cnt==p){
                    cout<<i<<" "<<j<<endl;
                    return 0;
                }
            }
        }
        else{
            for(int j=n;j>=1;--j){
                ++cnt;
                if(cnt==p){
                    cout<<i<<" "<<j<<endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}
