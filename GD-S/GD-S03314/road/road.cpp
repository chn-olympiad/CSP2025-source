#include<bits/stdc++.h>
using namespace std;
int n,m,k,f[100005],ans=0;
struct tree{
	int u,v,w;
}t[1000005];
struct d{
	int c,a[10005];
}q[15];
bool cmp(tree a,tree b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>t[i].u>>t[i].v>>t[i].w;
	}
	for(int i=0;i<k;i++){
		cin>>q[i].c;
		for(int j=1;j<=n;j++){
			cin>>q[i].a[j];
			int hj=m+i*n+j;
			t[hj].u=j;
			t[hj].v=n+i+1;
			t[hj].w=q[i].a[j]+q[i].c;
		}
	}
	sort(t+1,t+m+k*n+1,cmp);
	fill(f+1,f+n+k+1,0);
	int l=1;
	while(true){
		if(f[t[l].v]==0||f[t[l].u]==0){
			ans+=t[l].w;
			f[t[l].v]++;
			f[t[l].u]++;
		}
		bool p=true;
		for(int i=1;i<=n;i++){
			if(f[i]==0){
				p=false;
				break;
			}
		}
		if(p){
			break;
		}
		l++;
	}
	for(int i=1;i<=n+k;i++){
		if(i>n&&f[i]!=0){
			ans-=(f[i]-1)*q[i-n-1].c;
		}
	}
	cout<<ans;
	return 0;
}
