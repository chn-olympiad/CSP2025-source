#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct AAA{
	int t[5];
	int v;
}dp[N][5];

struct node{
	int	t[5];
}a[N];
bool B=1,C=1;
int solv_two(int n){
	int ans=-1;
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++){
			if(i==j) continue;
			ans=max(a[1].t[i]+a[2].t[j],ans);
		}
	return ans;
}
int solv_A(int n){
	int ans=0;
	priority_queue<int> q;
	for(int i=1;i<=n;i++)
	   q.push(a[i].t[1]);
	for(int i=1;i<=n/2;i++) {
		ans+=q.top();q.pop();
	}
	return ans;
}
void init(){
	for(int i=1;i<=3;i++){
		dp[1][i].v=a[1].t[i];
		dp[1][i].t[i]=1;
	}
}
int ans=0;
void solv(int n,int k,int num,int p[],int v){
	if(num>n) {ans=max(ans,v);return ;}
	for(int i=1;i<=3;i++){
		if(p[i]+1>k) continue;  
		p[i]++;
		solv(n,k,num+1,p,v+a[num].t[i]); 
		p[i]--;
		
	} 

}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--){
		int n;cin>>n;int k=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i].t[1]>>a[i].t[2]>>a[i].t[3];
			if(a[i].t[2]!=0) B=0;
			if(a[i].t[3]!=0) C=0;
		}
		if(n==2) {cout<<solv_two(n);continue;} 
		if(B&&C) {cout<<solv_A(n);continue;}
		int p[5]={0,0,0,0,0};
		solv(n,k,1,p,0);
		cout<<ans<<endl;
	}
	return 0;
} 

