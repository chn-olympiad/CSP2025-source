#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,use[N],sum[N],cnt=1,ans,num=1,idi[N],c[N],a[N][3];
void dfs(int d){
	if(d==n+1){
		num=1;
		for(int i=1;i<d;i++){
			for(int j=i+1;j<d;j++){
				if(idi[i]==idi[j]) num++;
				
			}
	}
		if(num<=n/2){
//			if(c[1]==4&&c[2]==4&&c[3]==5&&c[4]==5) cout<<114514;
			for(int i=1;i<d;i++) sum[cnt]+=c[i];
			cnt++;
		}
		return;
	}
	for(int i=1;i<=3;i++){
		c[d]=a[d][i];
		idi[d]=i;
		dfs(d+1);
	}
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int anss[N],ansss=1;
	while(t--){
		ans=0;
		memset(sum,0,sizeof sum);
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		dfs(1);
		for(int i=1;i<cnt;i++){
			ans=max(ans,sum[i]);
		}
		anss[ansss++]=ans;	
	}
	for(int i=1;i<ansss;i++) cout<<anss[i]<<" ";
	return 0;
}
