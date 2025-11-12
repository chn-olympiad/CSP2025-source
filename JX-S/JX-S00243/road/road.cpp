#include<bits/stdc++.h>
using namespace std;
int n,m,k;
vector<pair<int,int> > a[100005];
vector<pair<int,int> > b[100005];
int isx[100005];
int light_num = 0;
bool lights[100005];
bool checkd(){
    bool typ = false;
    for(int i =1;i<=n;i++) if(!lights[i]) typ = true;
    return typ;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i = 0;i<m;i++){
        int from,to,v;
        cin>>from>>to>>v;
        pair<int,int> temp = {to,v};
        a[from].push_back(temp);

    }
    for(int i =0;i<k;i++){
        cin>>isx[m + i + 1];
        for(int j =1;j<=m;j++){
            int v;
            cin>>v;
            pair<int,int> temp = {j,v};
            a[m + i + 1].push_back(temp);
        }
    }
    int minn = 2000000000;
    int xy = -1;
    int from = -1;
    int ui = 0;
    pair<int,int> cvg;
    while(checkd()){
        for(int i = 1;i<=n + k;i++){
            for(int j = 0;j<a[i].size();j++){
                //if(i == 6 && a[i].at(j).first == 1) cout<<minn<<" "<<a[i].at(j).second<<endl;
                if(a[i].at(j).second + isx[i]<minn && (!lights[i] || !lights[a[i].at(j).first])){
                    minn = a[i].at(j).second;
                    from = i;
                    ui = j;
                    cvg = {a[i].at(j).first,a[i].at(j).second};
                }
            }
        }

        light_num += (!lights[from]);
        light_num += (!lights[cvg.first]);
        lights[from] = true;
        lights[cvg.first] = true;
        a[from].at(ui).second = 2000000000;
        if(isx[from]!=0){
            cvg.second+=isx[from];
            isx[from] = 0;
        }

        b[from].push_back(cvg);
        minn = 2000000000;
    }

    int res = 0;
    for(int i = 1;i<=n+k;i++){
            for(int j = 0;j<b[i].size();j++){
                res+=b[i].at(j).second;
            }
    }
    cout<<res<<endl;
    //cout<<"Hello,world"<<endl;

    return 0;
}
