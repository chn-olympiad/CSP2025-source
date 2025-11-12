#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,T,ans,a[100005][35],b[35],cnt[5],p[100005],st[5],mark[100005];
void dfs(int s){
	if(cnt[1]>n/2||cnt[2]>n/2||cnt[3]>n/2)return;
	if(s==n+1){
		int sum=0;
		for(int i=1;i<=n;i++){
			sum+=b[i];
		}
		ans=max(sum,ans);
		return;
	}
	for(int i=1;i<=3;i++){
		b[s]=a[s][i];
		cnt[i]++;
		dfs(s+1);
		cnt[i]--;
	}
}
int get_id(int i){
	int res=a[i][1],id=1;
	if(res<a[i][2]){
		res=a[i][2],id=2;
	}
	if(res<a[i][3]){
		res=a[i][3],id=3;
	}
	return id;
}
int del(int i){
	st[1]=a[i][1];
	st[2]=a[i][2];
	st[3]=a[i][3];
	sort(st+1,st+4);
	return st[3]-st[2];
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(cnt,0,sizeof cnt);
		memset(mark,0,sizeof mark);
		ans=0;
		int sum=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%lld",&a[i][j]);
			}
			sum+=max(a[i][1],max(a[i][2],a[i][3]));
		}
		/*if(n<=10){
			dfs(1);
			cout<<ans<<endl;
		}else{*/
			for(int i=1;i<=n;i++){
				int id=get_id(i);
				cnt[id]++;
				mark[i]=id;
			}
			int tmp=0;
			if(cnt[1]>n/2)tmp=1;
			if(cnt[2]>n/2)tmp=2;
			if(cnt[3]>n/2)tmp=3;
			if(tmp==0)cout<<sum<<endl;
			else{
				int ct=0;
				for(int i=1;i<=n;i++){
					if(mark[i]==tmp)p[++ct]=del(i);
				}
				sort(p+1,p+ct+1);
				for(int i=1;i<=cnt[tmp]-n/2;i++)sum-=p[i];
				cout<<sum<<endl;
			}
		//}
		
	}
	return 0;
}
