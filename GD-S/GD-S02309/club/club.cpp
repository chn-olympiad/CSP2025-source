#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
struct nod{int a,b,c;}ai[N];
vector <int> v[4];
long long dp[N][4];//dp[i][j]:第i个员工选择第j部门的最高值 
//priority_queue<int,vector<int>,greater<int> > pqa,pqb,pqc;

/*void dfs(int now){
	if(now==n+1)return;
	for(int i=now;i<=n;i++){
		dfs(i);
		
	}
}*/
bool cmpa(nod x,nod y){
	
	return x.a>y.a;
	
}int n;
bool cmpb(nod x,nod y){
	if(x.b==y.b)return cmpa(x,y);
	return x.b>y.b;
}
bool cmpc(nod x,nod y){
	if(x.c==y.c)return cmpb(x,y);
	return x.c>y.c;
}
bool cmp(nod x,nod y){
	if(x.a<x.b&&x.b<x.c)return cmpa(x,y);
	if(x.b<x.a&&x.c>x.a)return cmpb(x,y);
	if(x.c<x.a&&x.c<x.b)return cmpc(x,y);
}
void slove(){
	
	cin>>n;	
	int flaga=0,fb=0;
	for(int i=1;i<=n;i++){
		cin>>ai[i].a>>ai[i].b>>ai[i].c;
		flaga=max(flaga,max(ai[i].b,ai[i].c));
		fb=max(fb,ai[i].c);
	}
	if(!flaga){
		sort(ai+1,ai+1+n,cmpa);
		long long ans;
		for(int i=1;i<=n/2;i++)ans+=ai[i].a;
		cout<<ans<<'\n';
		return;
	}
	/*for(int i=1;i<=n;i++){
		dp[i][1]=a[i].a;
		dp[i][2]=a[i].b;
		dp[i][3]=a[i].c;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){		
			dp[i][j]+=max(max(dp[i-1][1],dp[i-1][2]),dp[i-1][3]);
			
		}
	}
	cout<<max(dp[n][1],max(dp[n][2],dp[n][3]));
	*/
	if(!fb){
		
		sort(ai+1,ai+1+n,cmpb);	
		long long ans=0,ans1=0;
		for(int i=1;i<=n;i++){
			if(i<=n/2)ans+=ai[i].b;
			else ans+=ai[i].a;
		}
		for(int i=1;i<=n;i++){
			if(i<=n/2)ans1+=ai[i].a;
			else ans1+=ai[i].b;
		}
		cout<<max(ans,ans1)<<'\n';
		return ;
	}
	sort(ai+1,ai+n+1,cmp);
	long long ans=0,ans1=0,ans2=0;
		sort(ai+1,ai+1+n,cmpb);
		for(int i=1;i<=n;i++){
			if(i<=n/2)ans+=ai[i].b;
			else ans+=max(ai[i].a,ai[i].c);
		}
		sort(ai+1,ai+1+n,cmpa);
		for(int i=1;i<=n;i++){
			if(i<=n/2)ans1+=ai[i].a;
			else ans1+=max(ai[i].b,ai[i].c);
		}
		sort(ai+1,ai+1+n,cmpc);
		for(int i=1;i<=n;i++){
			if(i<=n/2)ans2+=ai[i].c;
			else ans2+=max(ai[i].b,ai[i].a);
		}
		cout<<max(max(ans,ans1),ans2)<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		
		slove();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
