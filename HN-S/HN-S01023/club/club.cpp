#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,a1[N],a2[N],a3[N],s1,s2,s3,d1,d2,d3,ans,m;
void dfs(int x){
	if(x==n+1){
		ans=max(ans,d1+d2+d3);
		return ;
	}
	if(s1<m){
		s1++,d1+=a1[x];
		dfs(x+1);
		s1--,d1-=a1[x];
	}
	if(s2<m){
		s2++,d2+=a2[x];
		dfs(x+1);
		s2--,d2-=a2[x];
	}
	if(s3<m){
		s3++,d3+=a3[x];
		dfs(x+1);
		s3--,d1-=a3[x];
	}
	return;
}
void dfs2(int x){
	if(x==n+1){
		ans=max(ans,d1+d2);
		return ;
	}
	if(s1<m){
		s1++,d1+=a1[x];
		dfs(x+1);
		s1--,d1-=a1[x];
	}
	if(s2<m){
		s2++,d2+=a2[x];
		dfs(x+1);
		s2--,d2-=a2[x];
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		s1=s2=s3=0;
		d1=d2=d3=0;
		ans=0;
		cin>>n;
		m=n/2;
		int st2=1,st3=1;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			if(a2[i]!=0) st2=0;
			if(a3[i]!=0) st3=0;
		}
		if(st2&&st3){
			sort(a1+1,a1+n+1);
			for(int i=n;i>=n-m+1;i--){
				ans+=a1[i];
			}
			cout<<ans;
		}else if(st3){
			dfs2(1);
			cout<<ans;
		}else{
			dfs(1);
			cout<<ans;
		}
		cout<<"\n";
	}
	return 0;
}
