#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int n;
int grade[N][5];	//第i个同学去1 2 3的分数 
vector<vector<int>> a(5,vector<int>(0));
bool AA=1;	//A成立 
bool BB=1;	//B成立 
bool vis[N];

int ans=0;
bool vi[N];

void init(){
	vector<vector<int>> b(5,vector<int>(0));
	a=b;
	memset(grade,0,sizeof(grade));
	memset(vis,0,sizeof(vis));
	AA=1;
	BB=1;
	ans=0;
	memset(vi,0,sizeof(vi));
}

void s_a(){
	int res=0;
	for(int i=0;i<n/2;i++){
		res+=a[1][i];
	}
	cout<<res<<endl;
	return ;
}

void s_b(){
	int res=0;
	priority_queue<int ,vector<int>,greater<int> > A,B;
	
	for(int i=1;i<=n;i++){
		if(grade[i][1]==max(grade[i][1],grade[i][2])){
			res+=grade[i][1];
			A.push(grade[i][2]-grade[i][1]);
		}
		else{
			res+=grade[i][2];
			B.push(grade[i][1]-grade[i][2]);
		}
	}
	
	if(A.size()>n/2){
		B.push(A.top());
		res+=A.top();
		A.pop();
	}
	if(B.size()>n/2){
		A.push(B.top());
		res+=B.top();
		B.pop();
	}
	
	cout<<res<<endl;
	return ;
}

int max_(int a,int b,int c){
	int mx=max(a,max(b,c));
	if(a==mx) return 1;
	else if(b==mx) return 2;
	else return 3;
}

void dfs(int now,int sum,int sa,int sb,int sc){
	if(now==n&&sa<=n/2&&sb<=n/2&&sc<=n/2){
		ans=max(ans,sum);
	}
	
	for(int i=1;i<=n;i++){
		if(vi[i]) continue ;
		vi[i]=1;
		for(int j=1;j<=3;j++){
			if(j==1){
				dfs(now++,sum+grade[i][1],sa+1,sb,sc);
			}
			if(j==2){
				dfs(now++,sum+grade[i][2],sa,sb+1,sc);
			}
			if(j==3){
				dfs(now++,sum+grade[i][3],sa,sb,sc+1);
			}
		}
		vi[i]=0;
	}
}

void s(){
	dfs(0,0,0,0,0);
	cout<<ans<<endl;
}

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int x,y,z;
		cin>>x>>y>>z;
		grade[i][1]=x;
		grade[i][2]=y;
		grade[i][3]=z;
		a[1].push_back(x);
		a[2].push_back(y);
		a[3].push_back(z);
		if(y!=0||z!=0) AA=0;
		if(z!=0) BB=0;
	}
	
	for(int i=1;i<=3;i++){
		sort(a[i].begin(),a[i].end(),greater<int>());
	}
	
	if(AA){
		s_a();
		return ;
	}
	else if(BB){
		s_b();
		return ;
	}
	else{
		s();
	}
}



signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		init();
		solve(); 
	} 
	return 0;
}  
