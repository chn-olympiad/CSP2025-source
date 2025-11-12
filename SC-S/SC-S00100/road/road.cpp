#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long c[15],ans;
struct li{
	int x,y,w;
}l[2000005],nl[2000005];
int f[10105];
bool cmp(li a1,li a2){
	return a1.w<=a2.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>l[i].x>>l[i].y>>l[i].w;
	}
	sort(l+1,l+1+m,cmp);
	for(int i=1;i<=m;i++){
		int x=l[i].x,y=l[i].y;
		if(f[x]!=f[y]){
			for(int j=1;j<=n;j++){
				if(f[j]==max(f[x],f[y])){
					f[j]=min(f[x],f[y]);
				}
			}
			ans+=l[i].w;
		}
	}
	long long cnt=0,ans1=0;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		ans1+=c[i];
		for(int j=1;j<=n;j++){
			l[m+j].x=n+cnt+1;
			l[m+j].y=j;
			cin>>l[m+j].w;
		}
		for(int j=1;j<=m+n;j++){
			nl[j].x=l[j].x;
			nl[j].y=l[j].y;
			nl[j].w=l[j].w;
		}
		sort(nl+1,nl+1+n+m,cmp);
		for(int j=1;j<=n+cnt+1;j++){
			f[j]=j;
		}
		for(int j=1;j<=n+m;j++){
			int x=nl[j].x,y=nl[j].y;
			if(f[x]!=f[y]){
				for(int o=1;o<=n+cnt+1;o++){
					if(f[o]==max(f[x],f[y])){
						f[o]=min(f[x],f[y]);
					}
				}
				int flag=0;
				for(int o=1;o<=n;o++){
					if(f[o]==1){
						flag=1;
					}
				}
				if(flag==0)break;
				ans1+=nl[j].w;
				if(ans1<=0||ans1>ans)break;
			}
		}
		if(ans1<ans&&ans1>=0){
			ans=ans1;
			m+=n;
			cnt++;
		}else{
			ans1-=c[i];
		}
	}
	cout<<ans;
	return 0;
}