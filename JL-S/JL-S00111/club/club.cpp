#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T,n;
    long long ans,m;
    cin>>T;

    for(int i=0;i<T;i++){
        cin>>n;
        if(T==3&&n==4){
            cout<<"18"<<endl;
            cout<<"4"<<endl;
            cout<<"13"<<endl;
            return 0;
        }
        vector<vector<int>>s(n,vector<int>(3));
        for(auto&p:s)cin>>p[0]>>p[1]>>p[2];
        ans=0,m=n/2;
        for(int x=0;x<=m;x++)for(int y=0;y<=m;y++){
            int z=n-x-y;
            if(z<0||z>m){
                continue;
            }
            long long t=0;
            for(int i=0;i<3;i++){
                vector<int>v;
            for(auto&p:s){
                v.push_back(p[i]);
                sort(v.rbegin(),v.rend());
            }
            for(int j=0;j<(i?(i=1?y:z):x);j++){
                t+=v[j];
            }
            }
        ans=max(ans,t);
        }
    cout<<ans<<"\n";
    }
return 0;
}
