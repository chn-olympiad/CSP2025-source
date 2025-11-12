#include<bits/stdc++.h>
using namespace std;
int T,n,ans,a[200005][4],st[4];
bool fa,fb;
void dfs(int s,int sum){
	if(s>n){
		ans=max(ans,sum);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(st[i]==n/2)continue;
		st[i]++;
		dfs(s+1,sum+a[s][i]);
		st[i]--;
	}
}
void dfs2(int s,int sum){
	if(s>n){
		ans=max(ans,sum);
		return ;
	}
	for(int i=1;i<=2;i++){
		if(st[i]==n/2)continue;
		st[i]++;
		dfs(s+1,sum+a[s][i]);
		st[i]--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][3])fa=1,fb=1;
			else if(a[i][2])fa=1;
		}
		if(fa==0){
			for(int i=1;i<=n;i++)
				for(int j=n;j>i;j--)
					if(a[j][1]>a[j-1][1])
						swap(a[j][1],a[j-1][1]);
			for(int i=1;i<=n/2;i++)ans+=a[i][1];
		}else if(fb==0){
			dfs2(1,0);
		}else{
			dfs(1,0);
		}
		cout<<ans<<endl;
	}
	return 0;
}
