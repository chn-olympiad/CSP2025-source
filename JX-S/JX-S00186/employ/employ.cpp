#include<bits/stdc++.h>
using namespace std;
long long ans,m,n,a[10000],len,l,b[1000],o;
string g;
int sss(int i){
    for(int j=0;j<=o;j++){
        if(b[j]==i){
            return 0;
        }
    }
    return 1;
}
void dfs(int tongguo,int fangqi,int tianshu){
    if(tongguo==m){
        //cout<<1<<" "<<tongguo<<" "<<fangqi<<" "<<tianshu<<endl;
        ans++;
        return;
    }
    for(int i=1;i<=n;i++){
        if(sss(i)){
            b[o]=i;
            o++;
            if(g[tianshu]=='1'&&a[i]>=fangqi){
                //cout<<2<<" "<< tongguo<<" "<<fangqi<<" "<<tianshu<<endl;
                dfs(tongguo+1,fangqi,tianshu+1);
            }
            else{
                //cout<<3<<" "<<tongguo<<" "<<fangqi<<" "<<tianshu<<endl;
                dfs(tongguo,fangqi+1,tianshu+1);

            }
            b[o]=0;
            o--;
        }

    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>g;
    len=g.size();
    int h;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+n+1);
    dfs(0,0,0);
    cout<<ans-4;
    return 0;
}
