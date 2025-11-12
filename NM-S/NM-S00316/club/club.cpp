#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5;
int t;
long long n,m;
struct node{
    int id;
    int pm1,pm2;
    int pm3;
    pair<int,int> ma,cd,x;
    int c;
}a[maxn];
bool cmp(node a,node b){
    if (a.c == b.c){
        if (a.ma.first == b.ma.first){
            if (a.cd.first == b.cd.first){
                return a.x.first>b.x.first;
            }
            return a.cd.first>b.cd.first;
        }
        return a.ma.first>b.ma.first;
    }
    return a.c>b.c;
}
bool cmp1(pair<int,int> a,pair<int,int> b){
    return a.first>b.first;
}
void solve(){
    cin>>n;
    m = n/2;
    vector<int> p[4];
    long long sum = 0;
    pair<int,int> ab[4];
    for (int i=1;i<=n;i++){
        cin>>a[i].pm1>>a[i].pm2>>a[i].pm3;
        a[i].id = i;
        ab[1] = make_pair(a[i].pm1,1);
        ab[2] = make_pair(a[i].pm2,2);
        ab[3] = make_pair(a[i].pm3,3);
        sort(ab+1,ab+4,cmp1);
        a[i].ma = ab[1];
        a[i].cd = ab[2];
        a[i].x=  ab[3];
        a[i].c= a[i].ma.first-a[i].x.first;
    }
    sort(a+1,a+1+n,cmp);
    /*for (int i=1;i<=n;i++){
        cout<<a[i].ma.first<<a[i].ma.second<<endl;
    }*/
    for (int i=1;i<=n;i++){
        int mb = a[i].ma.second;
        if (p[mb].size()>=m){
            int mbb = a[i].cd.second;
            p[mbb].push_back(a[i].id);
            sum += a[i].cd.first;
        }
        else {
            p[mb].push_back(a[i].id);
            sum += a[i].ma.first;
        }
    }
    cout<<sum<<endl;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while (t--){
        solve();
    }
    return 0;
}
