#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,x;
    cin>>n>>x;
    vector<int> r(n);
    for(int i=0;i<n;i++){
        cin>>r[i];
    }
    vector<pair<int,pair<int,int> > > ress;
    for(int b=0;b<n;b++){
        int tmp=0;
        for(int e=b;e<n;e++){
            tmp^=r[e];
            if(tmp==x){
                pair<int,int> res;
                res.first=b;
                res.second=e;
                ress.push_back(make_pair(b-e,res));
            }
        }
    }sort(ress.begin(),ress.end());
    int myres=0;
    vector<bool> visit(n,false);
    for(int i=0;i<ress.size();i++){
        bool can=true;
        pair<int,int> res=ress[i].second;
        for(int i=res.first;i<=res.second;i++){
            if(visit[i]){
                can=false;
            }
        }if(!can)continue;
        for(int i=res.first;i<=res.second;i++){
            visit[i]=true;
        }myres++;
    }cout<<myres;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
