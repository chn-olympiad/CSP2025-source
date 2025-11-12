#include<bits/stdc++.h>
using namespace std;
#define INT long long
INT n,m;
vector<pair<INT,bool> > data;
INT in;
bool comp(pair<INT,bool> a,pair<INT,bool> b){
    return a.first>b.first;
}
INT x=1,y=1;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(INT i=1;i<=n*m;++i){
        cin>>in;
        data.push_back({in,false});
    }
    data[0].second=true;
    sort(data.begin(),data.end(),comp);
    for(INT i=1;i<=n*m;++i){
        if(data[i-1].second==true){
            cout<<y<<' '<<x;
            exit(0);
        }
        if(y%2!=0){
            if(x<n){
                ++x;
            }else{
                ++y;
            }
        }else{
            if(x>1){
                --x;
            }else{
                ++y;
            }
        }
    }
    return 0;
}
