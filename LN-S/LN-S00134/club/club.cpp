#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
pair<int,int> a[N][4];
int n,cnt,cnt2,cnt3,res;
vector<pair<int,int>> s;
bool cmp(pair<int,int> a,pair<int,int> b){
    return a.first-a.second<b.first-b.second;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        res=cnt=cnt2=cnt3=0;
        s.clear();
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1].first>>a[i][2].first>>a[i][3].first;
            a[i][1].second=1;
            a[i][2].second=2;
            a[i][3].second=3;
            if(a[i][1].first<a[i][2].first) swap(a[i][1],a[i][2]);
            if(a[i][2].first<a[i][3].first) swap(a[i][2],a[i][3]);
            if(a[i][1].first<a[i][2].first) swap(a[i][1],a[i][2]);
            if(a[i][1].second==1) cnt++;
            else if(a[i][1].second==2) cnt2++;
            else cnt3++;
            res+=a[i][1].first;
        }
        if(cnt>n/2){
            for(int i=1;i<=n;i++){
                if(a[i][1].second==1) s.push_back({a[i][1].first,a[i][2].first});
            }
            sort(s.begin(),s.end(),cmp);
            for(int i=0;i<cnt-n/2;i++){
                res-=(s[i].first-s[i].second);
            }
        }else if(cnt2>n/2){
            for(int i=1;i<=n;i++){
                if(a[i][1].second==2) s.push_back({a[i][1].first,a[i][2].first});
            }
            sort(s.begin(),s.end(),cmp);
            for(int i=0;i<cnt2-n/2;i++){
                res-=(s[i].first-s[i].second);
            }
        }
        else if(cnt3>n/2){
            for(int i=1;i<=n;i++){
                if(a[i][1].second==3) s.push_back({a[i][1].first,a[i][2].first});
            }
            sort(s.begin(),s.end(),cmp);
            for(int i=0;i<cnt3-n/2;i++){
                res-=(s[i].first-s[i].second);
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}
