#include <bits/stdc++.h>
using namespace std;
#define lint long long
lint n,k,num[500010];
bool ck[500010];
queue<int> q;
int xr(lint x,lint y){
    lint ans=0;
    lint cnt=0;
    while(x||y){
        lint zx=x%2,zy=y%2;
        if(x==0) ans+=zy*pow(2,cnt);
        else if(y==0) ans+=zx*pow(2,cnt);
        else ans+=(!zx||!zy)*pow(2,cnt);
        x/=2,y/=2;
        cnt++;
    }
    return ans;
}
int as;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>num[i];
    int tot,r;
    bool flag=1;
    for(int l=1;l<=n;l++){
        if(ck[l]) continue;
        for(r=l;r<=n;r++){
            if(ck[r]) break;
            tot=num[l];flag=1;
            q.push(l);
            if(r>l){
                for(int i=l+1;i<=r;i++){
                    tot=xr(tot,num[i]);
                    if(ck[i]){
                        flag=0;
                        break;
                    }
                    q.push(i);
                }
            }
            if(tot==k&&flag){
                as++;
                while(!q.empty()){
                    ck[q.front()]=1;
                    q.pop();
                }
            }
        }

    }
    cout<<as;
    return 0;
}
