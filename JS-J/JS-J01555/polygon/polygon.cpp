#include <bits/stdc++.h>
using namespace std;
int a[5010];
bool f[25000010];
struct node{
    int num,step,mx,f[5010];
};
queue<node> q;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin >> n;
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    f[a[0]]=1;
    node x={a[0],1,a[0]};
    for(int i = 0;i<n;i++){
        x.f[i]=a[i];
    }
    q.push(x);
    int sum=0;
    while(!q.empty()){
        node nw=q.front();
        if(nw.num>nw.mx*2&&nw.step>=3){
            sum++;
        }
        q.pop();
        node cur;
        for(int i = 0;i<n;i++){
            if(nw.f[i]==0){
                continue;
            }
            cur={nw.num+nw.f[i],nw.step+1,max(nw.mx,nw.num+nw.f[i])};
            cur.f[i]=0;
            q.push(cur);
        }
    }
    cout << sum;
    return 0;
}
