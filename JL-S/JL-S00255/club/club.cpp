#include<bits/stdc++.h>
using namespace std;
int n,ans;
vector<int> cl[3];
void RE(){
    cin>>n;
    ans=0;
    cl[0].clear();cl[1].clear();cl[2].clear();
    for(int i=0;i<n;i++){
        int x,y,z;cin>>x>>y>>z;
        if(x>y && x>z)cl[0].push_back(x-max(y,z));
        if(y>z && y>x)cl[1].push_back(y-max(z,x));
        if(z>x && z>y)cl[2].push_back(z-max(x,y));
        ans += max(max(x,y),z);
    }
    int up = -1;
    for(int i=0;i<3;i++){
        if(cl[i].size()>n/2){
            up = i;
            break;
        }
    }
    if(up != -1){
        sort(cl[up].begin(),cl[up].end());
        for(int i=0;i<cl[up].size()-n/2;i++)
            ans -= cl[up][i];
    }
    cout<<ans<<endl;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T;cin>>T;
    while(T--)RE();
}
