#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
struct p{
	int x,y,z;
}a[100005],c[100005];
bool cmp(p o,p q){
	return o.x>q.x;
}
bool cmp1(p o,p q){
	return o.y>q.y;
}
bool cmp2(p o,p q){
	return o.z>q.z;
}
void dfs(int now,int sum,int cnt1,int cnt2,int cnt3){
	if(now>=n+1){
		ans=max(ans,sum);
//		cout<<cnt1<<" "<<cnt2<<" "<<cnt3<<" "<<ans<<endl;
		return;
	}
	if(cnt1<n/2)dfs(now+1,sum+a[now].x,cnt1+1,cnt2,cnt3);
	if(cnt2<n/2)dfs(now+1,sum+a[now].y,cnt1,cnt2+1,cnt3);
	if(cnt3<n/2)dfs(now+1,sum+a[now].z,cnt1,cnt2,cnt3+1);
}
void dfs1(int now,int sum,int cnt2,int cnt3){
	if(now>=n+1){
		ans=max(ans,sum);
//		cout<<cnt1<<" "<<cnt2<<" "<<cnt3<<" "<<ans<<endl;
		return;
	}
	if(cnt2<n/2)dfs1(now+1,sum+a[now].y,cnt2+1,cnt3);
	if(cnt3<n/2)dfs1(now+1,sum+a[now].z,cnt2,cnt3+1);
}
void dfs2(int now,int sum,int cnt1,int cnt3){
	if(now>=n+1){
		ans=max(ans,sum);
//		cout<<cnt1<<" "<<cnt2<<" "<<cnt3<<" "<<ans<<endl;
		return;
	}
	if(cnt1<n/2)dfs2(now+1,sum+a[now].x,cnt1+1,cnt3);
	if(cnt3<n/2)dfs2(now+1,sum+a[now].z,cnt1,cnt3+1);
}
void dfs3(int now,int sum,int cnt1,int cnt2){
	if(now>=n+1){
		ans=max(ans,sum);
//		cout<<cnt1<<" "<<cnt2<<" "<<cnt3<<" "<<ans<<endl;
		return;
	}
	if(cnt1<n/2)dfs3(now+1,sum+a[now].x,cnt1+1,cnt2);
	if(cnt2<n/2)dfs3(now+1,sum+a[now].y,cnt1,cnt2+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		int fl1=0,f1=0,f2=0,f3=0,fl2=0,fl3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y!=0||a[i].z!=0)	fl1=1;
			if(a[i].y!=0||a[i].x!=0)	fl3=1;
			if(a[i].x!=0||a[i].z!=0)	fl2=1;
			if(a[i].z!=0)f3=1;
			if(a[i].y!=0)f2=1;
			if(a[i].x!=0)f1=1;
		}
		if(!fl1){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++)	ans+=a[i].x;
			cout<<ans<<endl;
		}
		else if(!fl2){
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n/2;i++)	ans+=a[i].y;
			cout<<ans<<endl;
		}
		else if(!fl3){
			sort(a+1,a+n+1,cmp2);
			for(int i=1;i<=n/2;i++)	ans+=a[i].z;
			cout<<ans<<endl;
		}
		else if(!f1){
			dfs1(1,0,0,0);
			cout<<ans<<endl;
		}
		else if(!f2){
			dfs2(1,0,0,0);
			cout<<ans<<endl;
		}
		else if(!f3){
			dfs3(1,0,0,0);
			cout<<ans<<endl;
		}
		else if(n<=10){
//			cout<<"SFSDFSDF";
			dfs(1,0,0,0,0);
			cout<<ans<<endl;
		}
	}
	return 0;
}
