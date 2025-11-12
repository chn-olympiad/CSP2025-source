#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum[500005],c,l,m,ans;
queue<int>q[1050000];
stack<int>s;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]^a[i];
        q[sum[i]].push(i);
    }
    for(int i=1;i<=n;i++){
        c=sum[i]^k;
        if(c==0&&s.empty()){
            ans++;
            s.push(i);
        }
        else if(!q[c].empty()){
            l=q[c].front();
            if(!s.empty())m=s.top();
            else m=0;
            while(l<m&&!q[c].empty()){
                q[c].pop();
                l=q[c].front();
            }
            if(l<i&&l>=m){
                ans++;
                s.push(i);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
