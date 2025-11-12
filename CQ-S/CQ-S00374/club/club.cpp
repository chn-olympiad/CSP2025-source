#include<bits/stdc++.h>
#define int long long
#define N 100005
using namespace std;
int T;
int n;
int a[N][3];
int s[5];
void sol(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld %lld %lld",&a[i][0],&a[i][1],&a[i][2]);
	int ans=0;
	s[0]=s[1]=s[2]=0;
	priority_queue<int> q[3];
	for(int i=1;i<=n;i++){
		int mx=max(a[i][0],max(a[i][1],a[i][2]));
		ans+=mx;
		if(a[i][0]==mx){
			s[0]++;
			q[0].push(max(a[i][1],a[i][2])-a[i][0]);
		}
		else if(a[i][1]==mx){
			s[1]++;
			q[1].push(max(a[i][0],a[i][2])-a[i][1]);
		}
		else{
			s[2]++;
			q[2].push(max(a[i][0],a[i][1])-a[i][2]);
		}
	}
	if(s[0]>n/2){
		for(int i=1;i<=s[0]-n/2;i++) ans+=q[0].top(),q[0].pop();
	} 
	else if(s[1]>n/2){
		for(int i=1;i<=s[1]-n/2;i++) ans+=q[1].top(),q[1].pop();
	}
	else if(s[2]>n/2){
		for(int i=1;i<=s[2]-n/2;i++) ans+=q[2].top(),q[2].pop();
	}
	printf("%lld\n",ans);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--) sol();
	return 0;
} 
