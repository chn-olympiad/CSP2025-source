#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[100010][4],ans=0;
bool solvec(int x){
	int l1=0,l2=0,l3=0,ttans=0;
	for(int i=1;i<=n;i++){//特殊性质 C
		if(a[i][1]>a[i][2]&&a[i][1]>a[i][3])l1++,ttans+=a[i][1];
		else if(a[i][2]>a[i][3]&&a[i][2]>a[i][1])l2++,ttans+=a[i][2];
		else if(a[i][3]>a[i][1]&&a[i][3]>a[i][2])l3++,ttans+=a[i][3];
		else if(a[i][1]==a[i][2]&&a[i][1]>a[i][3]){
			if(l1<l2)l2++,ttans+=a[i][2];
			else l1++,ttans+=a[i][1];
		}
		else if(a[i][1]==a[i][3]&&a[i][1]>a[i][2]){
			if(l1<l3)l3++,ttans+=a[i][3];
			else l1++,ttans+=a[i][1];
		}
		else if(a[i][2]==a[i][3]&&a[i][2]>a[i][1]){
			if(l2<l3)l3++,ttans+=a[i][3];
			else l2++,ttans+=a[i][2];
		}
		else {
			if(l2<=l3&&l1<=l3)l3++,ttans+=a[i][3];
			else if(l2<=l1&&l3<=l1)l1++,ttans+=a[i][1];
			else if(l1<=l2&&l3<=l2)l2++,ttans+=a[i][2];
		}
	}
	if(max({l1,l2,l3})<=n/2){
		cout<<ttans+x<<"\n";
		return 1;
	}
	return 0;
}
int dfs(int x,int l1,int l2,int l3){
	if(x>n)return 0;
	int ans=0;
	if(l1<n/2)ans=max(ans,dfs(x+1,l1+1,l2,l3)+a[x][1]);
	if(l2<n/2)ans=max(ans,dfs(x+1,l1,l2+1,l3)+a[x][2]);
	if(l3<n/2)ans=max(ans,dfs(x+1,l1,l2,l3+1)+a[x][3]);
	return ans;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
			int t=min({a[i][1],a[i][2],a[i][3]});
			a[i][1]-=t,a[i][2]-=t,a[i][3]-=t;
			ans+=t;
		}
		if(solvec(ans))continue;
		if(n<=14){
			cout<<ans+dfs(0,0,0,0)<<"\n";
			continue;
		}
	}
	return 0;
}
/*
氮鸣羊 N2加速 
*/
