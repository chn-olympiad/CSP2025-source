#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
int n,k;
ull a[500005];
ull all[500005];
int cnt;
struct node{
    int i,j;
};
queue<node> q;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        all[i]=all[i-1]^a[i];
    }for(int i=1;i<=n;i++){
        for(int len=1;i+len-1<=n;len++){
            int j=i+len-1;
            if((all[j]^all[i-1])==k){
                q.push({i,j});
            }
        }
    }int now=0;
    node temp;
    while(q.size()){
        temp=q.front();
        q.pop();
        if(temp.i>now){
            cnt++;
            now=temp.j;
        }
    }cout<<cnt;
    return 0;
}
