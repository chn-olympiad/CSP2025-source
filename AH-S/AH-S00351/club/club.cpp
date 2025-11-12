#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{
	int a[4];
	//int p[4];
}a[N];
int t,n,s[4],cur[4];
long long ans,num;
bool f[N];
void dfs(int x){
	if(x>n){
		if(num>ans) ans=num;
		return;
	}
	for(int i=1;i<=n;i++){
		if(f[i]==0){			
			for(int j=1;j<=3;j++){
				if(s[j]<n/2){
					f[i]=1;
					num+=a[i].a[j];
					s[j]++;
					dfs(x+1);
					s[j]--;
					num-=a[i].a[j];
					f[i]=0;}
			}			
		}
	}
			
}
bool cmp(node p,node q){
	if(p.a[1]==q.a[1]){
		if(p.a[2]==q.a[2]){
			return p.a[3]>q.a[3];
		}
		return p.a[2]>q.a[2];
	}
	return p.a[1]>q.a[1];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a[1]>>a[i].a[2]>>a[i].a[3];
		}
		sort(a+1,a+n+1,cmp);
		if(a[1].a[2]==0&&a[1].a[3]==0&&a[n].a[2]==0&&a[n].a[3]==0){
			for(int i=1;i<=n/2;i++){
				ans+=a[i].a[1];
			}
			cout<<ans<<"\n";
			ans=0;
			continue;
		}else if(a[1].a[3]==0&&a[n].a[3]==0){
			for(int i=1;i<=n;i++){
				if(a[i].a[1]>a[i].a[2]) ans+=a[i].a[1];
				else ans+=a[i].a[2];}
			cout<<ans<<"\n";
			ans=0;
			continue;
		}
		num=0;
		dfs(1);
		cout<<ans<<"\n";
		ans=0;
	}
	return 0;
}
