#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b){
    return max({a.first,a.second.first,a.second.second}) > max({b.first, b.second.first, b.second.second});
}
int main(){
    ifstream cin("club.in");
    ofstream cout("club.out");
    int t;
    cin>>t;
    while(t--){
        int n,tot=0,cnta=0,cntb=0,cntc=0;
        cin>>n;
        vector<pair<int,pair<int,int>>> p(n);
        for(int i=0;i<n;i++){
            cin>> p[i].first >> p[i].second.first >> p[i].second.second;
        }
        sort(p.begin(),p.end(),cmp);
        for(int i=0;i<n;i++){
            int a = p[i].first, b = p[i].second.first, c = p[i].second.second;
            if(cnta >= n/2) a = -1;
            if(cntb >= n/2) b = -1;
            if(cntc >= n/2) c = -1;
            int k = max({a,b,c});
            if(a == k) cnta++;
            else if(b == k) cntb++;
            else if(c == k) cntc++;
            tot += k;
        }
        cout << tot << '\n';
    }
}
