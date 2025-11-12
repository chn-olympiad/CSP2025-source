#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
int t,a[100010][4];
priority_queue<pii>q11,q22,q33;
priority_queue<pii,vector<pii>,greater<pii>>q1,q2,q3;
int read(){
	int cnt=0,f=1;char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
	for(;isdigit(ch);ch=getchar()) cnt=cnt*10+ch-'0';
	return cnt*f;
}
void init(){
	memset(a,0,sizeof a);
	while(!q1.empty()) q1.pop();
	while(!q2.empty()) q2.pop();
	while(!q3.empty()) q3.pop();
}
void init1(){
	while(!q11.empty()) q11.pop();
	while(!q22.empty()) q22.pop();
	while(!q33.empty()) q33.pop();
}
signed main(){
	ios::sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		int n=read(),ans=0;
		init();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				a[i][j]=read();
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]){
				q1.push({a[i][1],i});
				ans+=a[i][1];
			}
			if(a[i][2]>a[i][1]&&a[i][2]>a[i][3]){
				q2.push({a[i][2],i});
				ans+=a[i][2];
			}
			if(a[i][3]>a[i][1]&&a[i][3]>a[i][2]){
				q3.push({a[i][3],i});
				ans+=a[i][3];
			}
		}
		while(q1.size()>n/2){
			int i=q1.top().second;
			ans-=q1.top().first;
			q1.pop();
			if(a[i][2]>=a[i][3]&&q2.size()<n/2){
				q2.push({a[i][2],i});
				ans+=a[i][2];
			}else{
				q3.push({a[i][3],i});
				ans+=a[i][3];
			}
		}
		while(q2.size()>n/2){
			int i=q2.top().second;
			ans-=q2.top().first;
			q2.pop();
			if(a[i][3]>=a[i][1]&&q3.size()<n/2){
				q3.push({a[i][3],i});
				ans+=a[i][3];
			}else{
				q1.push({a[i][1],i});
				ans+=a[i][1];
			}
		}
		while(q3.size()>n/2){
			int i=q3.top().second;
			ans-=q3.top().first;
			q3.pop();
			if(a[i][1]>=a[i][2]&&q1.size()<n/2){
				q1.push({a[i][1],i});
				ans+=a[i][1];
			}else{
				q2.push({a[i][2],i});
				ans+=a[i][2];
			}
		}
		int ans1=0;
		init1();
		for(int i=1;i<=n;i++){
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]){
				q11.push({a[i][1],i});
				ans1+=a[i][1];
			}
			if(a[i][2]>a[i][1]&&a[i][2]>a[i][3]){
				q22.push({a[i][2],i});
				ans1+=a[i][2];
			}
			if(a[i][3]>a[i][1]&&a[i][3]>a[i][2]){
				q33.push({a[i][3],i});
				ans1+=a[i][3];
			}
		}
		while(q11.size()>n/2){
			int i=q11.top().second;
			ans1-=q11.top().first;
			q11.pop();
			if(a[i][2]>=a[i][3]&&q22.size()<n/2){
				q22.push({a[i][2],i});
				ans1+=a[i][2];
			}else{
				q33.push({a[i][3],i});
				ans1+=a[i][3];
			}
		}
		while(q22.size()>n/2){
			int i=q22.top().second;
			ans1-=q22.top().first;
			q22.pop();
			if(a[i][3]>=a[i][1]&&q33.size()<n/2){
				q33.push({a[i][3],i});
				ans1+=a[i][3];
			}else{
				q11.push({a[i][1],i});
				ans1+=a[i][1];
			}
		}
		while(q33.size()>n/2){
			int i=q33.top().second;
			ans1-=q33.top().first;
			q33.pop();
			if(a[i][1]>=a[i][2]&&q11.size()<n/2){
				q11.push({a[i][1],i});
				ans1+=a[i][1];
			}else{
				q22.push({a[i][2],i});
				ans1+=a[i][2];
			}
		}
		cout<<max(ans,ans1)<<'\n';
	}
	return 0;
}
