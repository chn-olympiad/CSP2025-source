#include <bits/stdc++.h>
using namespace std;
struct P{
    int t[5005];

}nn;
int n,ans;
int s[5005];
int bfs(int a,int b,P x,int he);
int qiuhe(P tt);
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i];
    //for(int i=1;i<=n;i++){
    //    for(int j=i+1;j<=n;j++) if(s[i]>s[j]) swap(s[i],s[j]);
    //}
    sort(s+1,s+n+1);

    for(int i=n;i>=1;i--){
        memset(nn.t,0,sizeof(nn.t));
        for(int j=1;j<=i;j++) nn.t[j]=1;
        int o=qiuhe(nn);
        bfs(i,1,nn,o);
    }
    cout<<ans<<endl;
	return 0;
}
int bfs(int a,int b,P x,int he){
//    cout<<qiuhe(x)<<endl;
//    for(int j=1;j<=n;j++) cout<<x.t[j]<<" ";cout<<endl;

   // int o=qiuhe(x);
    if(he<=2*s[a]){
        return 0;
    }
    else{
      //  cout<<qiuhe(x)<<endl;
    //for(int j=1;j<=n;j++) cout<<x.t[j]<<" ";cout<<endl;
        ans++;
        for(int k=b;k<a;k++){
            x.t[k]=0;
            if(bfs(a,k+1,x,he-s[k])==0){
                    x.t[k]=1;
                    break;
            }
            x.t[k]=1;
        }
        return 1;
    }
}

int qiuhe(P tt){
    int sum=0;
    for(int w=1;w<=n;w++){
        if(tt.t[w]==1) sum+=s[w];
    }
    return sum;
}
