#include<bits/stdc++.h>
using namespace std;
struct qj{
    int l,r;
}b[1000005];
int a[1000005],n,m,k,ans,tot,dp[1005][1005];
int h[1000005];
//vector<int>p[1000005];
bool cmp(qj A,qj B){
    if(A.r!=B.r) return A.r<B.r;
    return A.l<B.l;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        h[i]=h[i-1]^a[i];
    }
    if(n<=2){
		if(a[1]==0&&a[2]==0) cout<<2<<endl;
        else if(a[1]==0||a[2]==0) cout<<1<<endl;
        else if((a[1]^a[2])==0) cout<<1<<endl;
        else cout<<0<<endl;
        return 0;
	}
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if((h[j]^h[i-1])==k){
				qj tp;
                tp.l=i;
                tp.r=j;
                b[++m]=tp;
            }
        }
    }
    sort(b+1,b+1+m,cmp);
    //for(int i=1;i<=m;i++) cout<<b[i].l<<b[i].r<<'\n';
    if(m==0){
        cout<<0<<'\n';
        return 0;
    }
    ans=1;
    int nr=b[1].r;
    for(int i=2;i<=m;i++){
        if(b[i].l>nr){
			ans++;
			nr=b[i].r;
		}
        
        
    }
    cout<<ans<<'\n';
    return 0;
}
/*
Jl blesses his students.
praise Jl.
*/
