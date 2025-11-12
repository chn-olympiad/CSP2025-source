#include<bits/stdc++.h>
using namespace std;
const int M=1e5+5;
int T,n,t[5],b[M],tt[M],m;
struct no{
	int x,y,id;
}c[M];
long long a[M][5],ans;
bool cmp(no a,no b){
	return a.x<b.x;
}
void compare(int x){
	if(a[x][1]>=a[x][2]&&a[x][1]>=a[x][3]){//ѡ1 
		t[1]++;b[x]=1;
		ans+=a[x][1];
		return ;
	}
	if(a[x][2]>=a[x][1]&&a[x][2]>=a[x][3]){//ѡ2 
		t[2]++;b[x]=2;
		ans+=a[x][2];
		return ;
	}
	t[3]++;b[x]=3;//ѡ3 
	ans+=a[x][3];
	return ;
}
bool w2(int ans,int sum){
	if(t[1]<=m&&t[2]<=m&&t[3]<=m){
		printf("%lld\n",ans-sum);
		return 1;
	}
	return 0;
}
void solve(){
	scanf("%d",&n);
	m=n/2;ans=0;
	for(int i=1;i<=n;i++){
		scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
		compare(i);
	}
	int sum=0;
	if(w2(ans,0))return;
	if(t[1]>m){
		int x=t[1]-m;
		for(int i=1;i<=n;i++){
			if(b[i]!=1)continue;
			if(a[i][2]>a[i][3])c[i].x=a[i][1]-a[i][2],c[i].y=2;
			else c[i].x=a[i][1]-a[i][3],c[i].y=3;
			c[i].id=i;
		}
		sort(c+1,c+1+n,cmp);
		int i=1; 
		while(x--){
			sum+=c[i].x;
			t[1]--;
			t[c[i].y]++;
			b[c[i].id]=c[i].y;i++;
		}
		w2(ans,sum);
		return;
	}
	if(t[2]>m){
		int x=t[2]-m;
		for(int i=1;i<=n;i++){
			if(b[i]!=2)continue;
			if(a[i][1]>a[i][3])c[i].x=a[i][2]-a[i][1],c[i].y=1,c[i].id=i;
			else c[i].x=a[i][2]-a[i][3],c[i].y=3,c[i].id=i;
		}
		sort(c+1,c+1+n,cmp);
		int i=1; 
		while(x--){
			sum+=c[i].x;
			t[2]--;
			t[c[i].y]++;
			b[c[i].id]=c[i].y;i++;
		}
		w2(ans,sum);
		return ;
	}
	if(t[3]>m){
		int x=t[3]-m;
		for(int i=1;i<=n;i++){
			if(b[i]!=3)continue;
			if(a[i][2]>a[i][1])c[i].x=a[i][3]-a[i][2],c[i].y=2,c[i].id=i;
			else c[i].x=a[i][3]-a[i][1],c[i].y=1,c[i].id=i;
		}
		sort(c+1,c+1+n,cmp);
		int i=1; 
		while(x--){
			sum+=c[i].x;
			t[3]--;
			t[c[i].y]++;
			b[c[i].id]=c[i].y;i++;
		}
		w2(ans,sum);
		return ;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>T;
	while(T--){
		memset(t,0,sizeof(t));
		memset(c,0x3f,sizeof(c));
		solve();
	}
	
	return 0;
}
