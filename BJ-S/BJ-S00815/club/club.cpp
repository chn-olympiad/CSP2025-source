#include<bits/stdc++.h>
using namespace std;
int T,n,ans,cntn,idx[3],val[100010][3],op[100010];
void dfs(int idxx[],int step,int cnt){
    if(step>n){
        ans=max(ans,cnt);
        return;
    }
    for(int i=0;i<3;i++){
        if(idxx[i]==cntn) continue;
        idxx[i]++;
        dfs(idxx,step+1,cnt+val[step][i]);
        idxx[i]--;
    }
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        cntn=n/2;
        ans=idx[0]=idx[1]=idx[2]=0;
        for(int i=1;i<=n;i++){
            cin>>val[i][0]>>val[i][1]>>val[i][2];
        }
        dfs(idx,1,0);
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
