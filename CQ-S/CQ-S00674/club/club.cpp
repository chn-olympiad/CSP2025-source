#include<bits/stdc++.h>
using namespace std;
int n,ans,d[100005][14],a1[100005],a2[100005],a3[100005],t;
int dfs(int id,int sum,int aa,int aaa,int aaaa){
	if(aa+aaa+aaaa==n&&aa<=n/2&&aaa<=n/2&&aaaa<=n/2){
		ans=max(ans,sum);
		return 0;
	}
	if(id==n+1){
		return 0;
	}
	dfs(id+1,sum+a1[id],aa+1,aaa,aaaa);
	dfs(id+1,sum+a2[id],aa,aaa+1,aaaa);
	dfs(id+1,sum+a3[id],aa,aaa,aaaa+1);
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int f=0;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			if(a2[i]||a3[i])f=1;
		} 
		if(n<=17){
			dfs(1,0,0,0,0);
			cout<<ans<<'\n';
		}else if(f==0){
			sort(a1+1,a1+n+1);
			int sum=0;
			for(int i=n;i>=n-n/2+1;i--){
				sum+=a1[i];
			}
			cout<<sum<<'\n';
		}else if(n<=10000){
			for(int i=1;i<=n;i++){
				for(int j=n/2;j>=1;j--){
					d[j][1]=max(d[j-1][1]+a1[i],d[j][1]);
					d[j][2]=max(d[j-1][2]+a2[i],d[j][2]);
					d[j][3]=max(d[j][3],d[j-1][3]+a3[i]);
				}
			}
			for(int i=1;i<=n/2;i++){
				ans=max(ans,max(d[i][1],max(d[i][2],d[i][3])));
			}
			cout<<ans<<'\n';
		}
	} 
	
	return 0;
}
