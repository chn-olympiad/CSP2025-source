#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
int n,k,a[N],idx=0;
struct qujian{
    int l,r;
};
qujian ok[N];
bool check(int x,int y){//xor x~y in a  ==  k?
    int xor1=0;
    for(int i=x;i<=y;++i){
        xor1^=a[i];
    }
    if(xor1==k)return 1;
    return 0;
}
bool dfs(int now,int cnt,int last){
    if(now>idx||cnt==0){
        if(cnt==0){
            //cout<<"That's OK!\n";
            return 1;
        }
        //cout<<"Bad choise!\n";
        return 0;
    }
    if(dfs(now+1,cnt,last))return 1;
    if(ok[now].l>last){
        //cout<<"choose "<<now<<"th.\n";
        if(dfs(now+1,cnt-1,ok[now].r))return 1;
    }
    return 0;
}
bool check2(int num){//can choose num qujians in all?
    return dfs(1,num,0);
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i){
        for(int j=i;j<=n;++j){
            if(check(i,j))ok[++idx]={i,j};
        }
    }
    //cout<<"There are "<<idx<<" good qujian.\n";
    //cout<<"They are ";
    //for(int i=1;i<=idx;++i)cout<<ok[i].l<<','<<ok[i].r<<'\n';
    for(int i=idx;i>=1;--i){
        if(check2(i)){
            //cout<<"good!\n";
            cout<<i;
            return 0;
        }
    }
    cout<<0;
    return 0;
}
