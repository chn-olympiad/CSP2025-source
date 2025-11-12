#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Trie{
    int index=-1;
    int child[2];
} trie[500000*6];
int cnt = 1;
void insert(ll v,int i){
    int node = 0;
    for(int i=0;i<20;i++){
        if(!trie[node].child[v&1])
            trie[node].child[v&1] = cnt++;
        node = trie[node].child[v&1];
        v >>= 1;
    }
    trie[node].index = i;
}
int find(ll v){
    int node = 0;
    for(int i=0;i<20;i++){
        if(!trie[node].child[v&1])
            return -1;
        node = trie[node].child[v&1];
        v >>= 1;
    }
    return trie[node].index;
}
int n,j,s;
ll k,a[500000*2];
vector<pair<int,int>> vpii;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)a[i]^=a[i-1];
    for(int i=0;i<=n;i++){
        int res = find(k^a[i]);
        if(res!=-1){
            vpii.push_back(make_pair(res+1,i));
        }
        insert(a[i],i);
    }
    for(auto i : vpii){
        if(i.first >= j){
            j = i.second+1;
            s++;
        }
    }
    cout<<s;
}
