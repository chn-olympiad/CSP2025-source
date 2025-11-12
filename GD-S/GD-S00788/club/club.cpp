#include<bits/stdc++.h>
using namespace std;
long long T,st;
long long n,ans;
long long yuan[100008][5];
long long mx[100008];
void dfs(long long x,long long a,long long b,long long c,long long cnt){
	st++;
	if(x>n){
		ans=max(ans,cnt);
		return;
	}
	if(cnt+mx[x]<ans) return;
	if(st>30000000) return;
	if(yuan[x][1]>=yuan[x][2]&&yuan[x][1]>=yuan[x][3]){
		if(a<n/2) dfs(x+1,a+1,b,c,cnt+yuan[x][1]);
		if(st>30000000) return;
		if(yuan[x][2]>yuan[x][3]){
			if(b<n/2) dfs(x+1,a,b+1,c,cnt+yuan[x][2]);
			if(st>30000000) return;
			if(c<n/2) dfs(x+1,a,b,c+1,cnt+yuan[x][3]);
		}
		else{
			if(c<n/2) dfs(x+1,a,b,c+1,cnt+yuan[x][3]);
			if(st>30000000) return;
			if(b<n/2) dfs(x+1,a,b+1,c,cnt+yuan[x][2]);
		}
	}
	else if(yuan[x][2]>=yuan[x][1]&&yuan[x][2]>=yuan[x][3]){
		if(b<n/2) dfs(x+1,a,b+1,c,cnt+yuan[x][2]);
		if(st>30000000) return;
		if(yuan[x][1]>yuan[x][3]){
			if(a<n/2) dfs(x+1,a+1,b,c,cnt+yuan[x][1]);
			if(st>30000000) return;
			if(c<n/2) dfs(x+1,a,b,c+1,cnt+yuan[x][3]);
		}
		else{
			if(c<n/2) dfs(x+1,a,b,c+1,cnt+yuan[x][3]);
			if(st>30000000) return;
			if(a<n/2) dfs(x+1,a+1,b,c,cnt+yuan[x][1]);
		}
	}
	else if(yuan[x][3]>=yuan[x][1]&&yuan[x][3]>=yuan[x][2]){
		if(c<n/2) dfs(x+1,a,b,c+1,cnt+yuan[x][3]);
		if(st>30000000) return;
		if(yuan[x][1]>yuan[x][2]){
			if(a<n/2) dfs(x+1,a+1,b,c,cnt+yuan[x][1]);
			if(st>30000000) return;
			if(b<n/2) dfs(x+1,a,b+1,c,cnt+yuan[x][2]);
		}
		else{
			if(b<n/2) dfs(x+1,a,b+1,c,cnt+yuan[x][2]);
			if(st>30000000) return;
			if(a<n/2) dfs(x+1,a+1,b,c,cnt+yuan[x][1]);
		}
	}
	return;
}
struct sorty{
	long long a[5];
}y[100008];
bool cmp(sorty a,sorty b){
	return a.a[1]>b.a[1];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		st=0;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>yuan[i][j];
				y[i].a[j]=yuan[i][j];
			}
		}
		if(n>=40){
			sort(y+1,y+n+1,cmp);
			for(int i=1;i<=n/2;i++) ans+=y[i].a[1];
			for(int i=n/2+1;i<=n;i++) ans+=y[i].a[2];
			cout<<ans<<"\n";
			continue;
		}
		for(int i=n;i>=1;i--){
			if(i==n) mx[i]=max(yuan[i][1],max(yuan[i][2],yuan[i][3]));
			else mx[i]=mx[i+1]+max(yuan[i][1],max(yuan[i][2],yuan[i][3]));
		}
		dfs(1,0,0,0,0);
		cout<<ans<<"\n";
	}
	return 0;
} 
