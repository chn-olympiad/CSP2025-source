#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[100010][4];
int len[4];
int s[100010];
long long sum=0;
struct g{
    int ma,id;
} mma[100010];
bool cmp(g a,g b){
    return a.ma>b.ma;
}
void dfs(int x){
    if(x==n+1){
        long long ans=0;
        for(int i=1;i<=n;i++){
            ans+=a[i][s[i]];
            //cout<<i<<":"<<s[i]<<endl;
             len[s[i]]++;
        }
        //cout<<len[1]<<" "<<len[2]<<" "<<len[3]<<endl;
        if(len[1]<=n/2&&len[2]<=n/2&&len[3]<=n/2) sum=max(sum,ans);
        len[1]=len[2]=len[3]=0;
        return ;
    }
        s[x]=1;
        dfs(x+1);



        s[x]=2;
        //len[2]++;
        dfs(x+1);
        //len[2]--;


        s[x]=3;
        //len[3]++;
        dfs(x+1);
        //len[3]--;


}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        sum=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
            }
        }
        dfs(1);
        cout<<sum<<endl;
    }
    return 0;
}
