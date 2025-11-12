#include<bits/stdc++.h>
using namespace std;
struct S{
    int st,ed;
}b[500050];
bool cmp(S x,S y){
    return x.ed<y.ed;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int a[n+5];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int t=1;
    for(int i=1;i<=n;i++){
        int x=a[i];
        if(x==k) {
            b[t].st=i,b[t].ed=i;
            t++;
            continue;
        }
        for(int j=i+1;j<=n;j++){
            x=x^a[j];
            if(x==k) {
                b[t].st=i,b[t].ed=j;
                t++;
                break;
            }
        }
    }
    sort(b+1,b+t+1,cmp);
    int cnt=0,ended=0;
    for(int i=1;i<=t;i++){
        if(b[i].st>ended){
            cnt++;
            ended=b[i].ed;
        }
    }
    cout<<cnt;
    return 0;
}
