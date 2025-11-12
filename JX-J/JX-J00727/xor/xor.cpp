#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7,A=3e5+7;
int n,k,a[N],lst[A];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]^=a[i-1];
    }
    for(int i=0;i<A;i++)lst[i]=-1;
    priority_queue<pair<int,int> > pq;
    for(int i=n;i>=0;i--){
        pq.push(make_pair(-lst[a[i]^k],i));
        lst[a[i]]=i;
    }
    int pres=0,cnt=0;
    while(pq.size()){
        pair<int,int> t=pq.top(); pq.pop();
        int x=-t.first,y=t.second;
        if(x<pres||y<pres)continue;
        cnt++;
        pres=x;
    }
    cout<<cnt;
    return 0;
}