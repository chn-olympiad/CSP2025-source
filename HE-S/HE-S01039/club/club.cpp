#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n;

struct edge{
	int a,b,c;
	bool st;
	int s[5];
	
}e[N];
int cnt[5];
bool cmp(edge x,edge y){
	if(x.s[3]!=y.s[3]) return x.s[3]<y.s[3];
	else if(x.s[2]!=y.s[2]) return x.s[2]<y.s[2];
	else return x.s[1]<y.s[1];
}
int find(int x,int y){
	if(x==e[y].a) return 1;
	else if(x==e[y].b) return 2;
	else return 3;
}

int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >>t;
	while(t--){
		
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >>e[i].a >>e[i].b >>e[i].c;
		int x=e[i].a,y=e[i].b,z=e[i].c;
		e[i].s[1]=x;
		e[i].s[2]=y;
		e[i].s[3]=z;
		sort(e[i].s+1,e[i].s+4);
		
	}
	sort(e+1,e+n+1,cmp);

	int ansz=0;
	for(int j=1;j<=n;j++){
		int ans=0;
		memset(cnt,0,sizeof cnt);
		for(int i=j;i<=n;i++){
		
			if(cnt[find(e[i].s[3],i)]<n/2) cnt[find(e[i].s[3],i)]++,ans+=e[i].s[3];
			else if(cnt[find(e[i].s[2],i)]<n/2) cnt[find(e[i].s[2],i)]++,ans+=e[i].s[2];
			else if(cnt[find(e[i].s[1],i)]<n/2) cnt[find(e[i].s[1],i)]++,ans+=e[i].s[1];
		}
		for(int i=1;i<=j-1;i++){
			if(cnt[find(e[i].s[3],i)]<n/2) cnt[find(e[i].s[3],i)]++,ans+=e[i].s[3];
			else if(cnt[find(e[i].s[2],i)]<n/2) cnt[find(e[i].s[2],i)]++,ans+=e[i].s[2];
			else if(cnt[find(e[i].s[1],i)]<n/2) cnt[find(e[i].s[1],i)]++,ans+=e[i].s[1];
		}
		ansz=max(ansz,ans);
	}

	for(int j=n;j;j--){	memset(cnt,0,sizeof cnt);
		int ans=0;
		for(int i=j;i;i--){
		if(cnt[find(e[i].s[3],i)]<n/2) cnt[find(e[i].s[3],i)]++,ans+=e[i].s[3];
		else if(cnt[find(e[i].s[2],i)]<n/2) cnt[find(e[i].s[2],i)]++,ans+=e[i].s[2];
		else if(cnt[find(e[i].s[1],i)]<n/2) cnt[find(e[i].s[1],i)]++,ans+=e[i].s[1];
	}
	for(int i=n;i>=j+1;i--){
		if(cnt[find(e[i].s[3],i)]<n/2) cnt[find(e[i].s[3],i)]++,ans+=e[i].s[3];
		else if(cnt[find(e[i].s[2],i)]<n/2) cnt[find(e[i].s[2],i)]++,ans+=e[i].s[2];
		else if(cnt[find(e[i].s[1],i)]<n/2) cnt[find(e[i].s[1],i)]++,ans+=e[i].s[1];
	}
	ansz=max(ansz,ans);
	}
		
	cout <<ansz <<'\n';
	}
	return 0;
}
