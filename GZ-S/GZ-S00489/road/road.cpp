//GZ-S00489 贵阳市白云区华师一学校 雷国粲
#include<bits/stdc++.h>
struct str{
	int next[1000010];
	int idx;
	int ab[1000010];
}aa[1000010];
using namespace std;
int q,a,b,c,d;
int n,m,k,ans=INT_MAX;
bool t[1010];
void abc(int x,int y,int res){
	if(t[x]==true) return;
	if(y==n+k){
		ans=min(ans,res);
		return;
	}
	t[x]=true;
	for(int i=1;i<=aa[x].idx;i++){
		abc(aa[x].next[i],y+1,res+aa[x].ab[i]);
		t[aa[x].next[i]]=false;
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>q;
		aa[a].idx++;
		aa[a].next[aa[a].idx]=b;
		aa[a].ab[aa[a].idx]=q;
		aa[b].idx++;
		aa[b].next[aa[b].idx]=a;
		aa[b].ab[aa[b].idx]=q;
	}
	for(int i=1;i<=k;i++){
		cin>>q;
		for(int j=1;j<=n;j++){
			cin>>a;
			aa[i+n].idx++;
			aa[i+n].next[aa[i+n].idx]=j;
			aa[i+n].ab[aa[i+n].idx]=q+a;
			aa[j].idx++;
			aa[j].next[aa[j].idx]=i+n;
			aa[j].ab[aa[j].idx]=q+a;
		}
	}
	for(int i=1;i<=n+k;i++){
		abc(i,1,0);
		t[i]=false;
	}
	cout<<ans;
	return 0;
}
