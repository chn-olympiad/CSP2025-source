#include<bits/stdc++.h>
using namespace std;
#define int long long
struct edge{
	int u,num;
};
int a[100005][4];
edge b[4];
int maxn[100005];
int z[100005];
int y[5];
bool cmp(edge x,edge y){
	return x.num>y.num;
}
bool cmp1(int x,int y){
	return x>y;
}
signed main(){

	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		queue<int> q[4];
		int cc=0;
		for(int i=1;i<=n;i++){
			int cnt=0;
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]){
				q[1].push(i);cnt++;++cc;
				maxn[i]=max(a[i][2],a[i][3]);
			}
			if(a[i][2]>a[i][1]&&a[i][2]>a[i][3]){
				q[2].push(i);cnt++;
				maxn[i]=max(a[i][1],a[i][3]);
			}
			if(a[i][3]>a[i][2]&&a[i][3]>a[i][1]){
				q[3].push(i);cnt++;
				maxn[i]=max(a[i][2],a[i][1]);
			}
			if(cnt==0){
				if(a[i][1]==a[i][2]&&a[i][1]==a[i][3]){
					q[1].push(i);
					maxn[i]=a[i][1];
					continue;
				}
				if(a[i][1]==a[i][2]){
					q[1].push(i);
					maxn[i]=a[i][2];
					continue;
				}
				if(a[i][2]==a[i][3]){
					q[2].push(i);
					maxn[i]=a[i][3];
					continue;
				}
				if(a[i][1]==a[i][3]){
					q[1].push(i);
					maxn[i]=a[i][3];
					continue;
				}
			}
		}
		b[1].num=q[1].size();
		b[2].num=q[2].size();
		b[3].num=q[3].size();
		b[1].u=1;
		b[2].u=2;
		b[3].u=3;
		sort(b+1,b+3+1,cmp);
		if(b[1].num<=n/2){
			int ans=0;
			while(!q[1].empty()){
				int kkk=q[1].front();
				q[1].pop();
				ans+=a[kkk][1];
			}
			while(!q[2].empty()){
				int kkk=q[2].front();
				q[2].pop();
				ans+=a[kkk][2];
			}
			while(!q[3].empty()){
				int kkk=q[3].front();
				q[3].pop();
				ans+=a[kkk][3];
			}
			cout<<ans<<"\n";
		}
		else{
			int tot=0;
			int ans=0;
			while(!q[b[1].u].empty()){
				int kkk=q[b[1].u].front();
				q[b[1].u].pop();
				ans+=a[kkk][b[1].u];
				z[++tot]=(maxn[kkk]-a[kkk][b[1].u]);
			}
			while(!q[b[2].u].empty()){
				int kkk=q[b[2].u].front();
				q[b[2].u].pop();
				ans+=a[kkk][b[2].u];
			}
			while(!q[b[3].u].empty()){
				int kkk=q[b[3].u].front();
				q[b[3].u].pop();
				ans+=a[kkk][b[3].u];
			}
			sort(z+1,z+tot+1,cmp1);
			for(int i=1;i<=b[1].num-n/2;i++)ans+=z[i];
			cout<<ans<<"\n";
		}
	}
	return 0;
}