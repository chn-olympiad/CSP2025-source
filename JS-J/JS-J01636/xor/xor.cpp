#include<bits/stdc++.h>
using namespace std;
int a[500005];
int prexor[500005];
int need[500005];
vector<pair<int,int> >seg;
int lstrgt;
int n,k;
unordered_map<int,vector<int> >nip;
bool cmp(pair<int,int>a,pair<int,int>b){
    if(a.second==b.second)return a.first<b.first;
    return a.second<b.second;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        prexor[i]=prexor[i-1]^a[i];
        need[i]=k^prexor[i-1];
        nip[prexor[i]].push_back(i);
    }
    for(int i=1;i<=n;i++){
        auto t=lower_bound(nip[need[i]].begin(),nip[need[i]].end(),i);
        if(t==nip[need[i]].end())continue;
        seg.push_back({i,*t});
        //printf("%d %d\n",seg[seg.size()-1].first,seg[seg.size()-1].second);
    }
    sort(seg.begin(),seg.end(),cmp);
    int t=seg.size();
    int segcnt=0;
    for(int i=0;i<t;i++){
        if(seg[i].first>lstrgt){
            segcnt++;
            lstrgt=seg[i].second;
        }
    }
    printf("%d",segcnt);
    return 0;
}
