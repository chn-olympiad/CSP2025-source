#include<bits/stdc++.h>
using namespace std;

#define ll long long

struct node{
    int st;
    int ed;
};

int n,k;
int cnt=0;
int s[500010];
int t[500010];
vector<int> cs[1100000];
vector<int> ct[1100000];
vector<node> p;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    cs[s[0]].push_back(0);
    ct[t[k]].push_back(k);
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        s[i]=s[i-1]^x;
        t[i]=s[i]^k;
        cs[s[i]].push_back(i);
        ct[t[i]].push_back(i);
    }
    for(int i=0;i<1050000;i++) for(int j=0;j<cs[i].size();j++) for(int k=0;k<ct[i].size();k++){
        node loc;
        if(cs[i][j]>=ct[i][k]) continue;
        loc.st=cs[i][j];
        loc.ed=ct[i][k];
        p.push_back(loc);
    }
    sort(p.begin(),p.end(),[](node x,node y){
        return x.ed<y.ed;
    });
    int end=-1;
    for(int i=0;i<p.size();i++){
        if(p[i].st<end) continue;
        cnt++;
        end=p[i].ed;
    }
    cout<<cnt;
    return 0;
}
