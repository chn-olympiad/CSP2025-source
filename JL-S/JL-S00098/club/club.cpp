#include<bits/stdc++.h>
using namespace std;
int T,n,ans,a[200010],b[200010],c[200010];
void dfs(int q,int s1,int s2,int s3,int s){
	if(q==n+1&&s1<=n/2&&s2<=n/2&&s3<=n/2){
		ans=max(ans,s);
		return ;
	}
	dfs(q+1,s1+1,s2,s3,s+a[q]);
	dfs(q+1,s1,s2+1,s3,s+b[q]);
	dfs(q+1,s1,s2,s3+1,s+c[q]);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    for(int t=1;t<=T;t++){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
        }
        dfs(1,0,0,0,0);
        cout<<ans<<endl;
    }
    return 0;
}
