//GZ-S00381 贵阳市第三中学 胡景涵 
#include<bits/stdc++.h>
using namespace std;bool ifb=1;
int n,vis[100001],f[4][100001],dp[100001][3];
struct Inf_{
	int fi,stu,club;
	Inf_(int Fi,int Stu,int Club){
		fi=Fi,stu=Stu,club=Club;
	}
};
bool operator < (Inf_ a,Inf_ b){
	if(a.fi!=b.fi) return a.fi<b.fi;
	else if(a.stu!=b.stu) return a.stu<b.stu;
	return a.club<b.club;
}
priority_queue<int> q;
int ans;
int cnt[4];
deque<int> went;
void dfs(int i,int club,int sum){
	cnt[club]++;
	sum+=f[club][i];
	if(cnt[club]>n/2) return;
	if(i==n+1){
		ans=max(sum,ans);
		//cout<<sum<<"   max:"<<ans<<endl;
		//for(int i=went.size()-1;i>=0;i--) cout<<went[i]<<' ';
		//cout<<endl; 
		return;
	}
	//went.push_front(1);
	dfs(i+1,1,sum);
	cnt[1]--;
	//went.pop_front();
	
	//went.push_front(2);
	dfs(i+1,2,sum);
	//went.pop_front();
	cnt[2]--;
	//went.push_front(3);
	if(!ifb){
	dfs(i+1,3,sum);
	cnt[3]--;
	}
	//went.pop_front();
	return;
}

void solve(){
	ans=0;
	cin>>n;
	int sum=0;
	
	for(int i=1;i<=n;i++){
		cin>>f[1][i]>>f[2][i]>>f[3][i];
		if(f[3][i]>0) ifb=0;
		q.push(f[1][i]);
	}
	if(n>=1000){
		for(int i=1;i<=n/2;i++){
			sum+=q.top();q.pop();
		}
		cout<<sum<<endl;
		return ;
	}
	//went.push_front(1);
	dfs(1,1,0);
	cnt[1]--;
	//went.pop_front();went.push_front(2);
	dfs(1,2,0);//went.pop_front();went.push_front(3);
	cnt[2]--;
	if(!ifb){
	dfs(1,3,0);
	//went.pop_front();
	cnt[3]--;
	}
	cout<<ans<<endl;
	cnt[1]=cnt[2]=cnt[3]=0;
	for(int i=1;i<=n;i++) f[1][i]=f[2][i]=f[3][i]=0;
	return;
}
int main(){
	freopen("club.in","r",stdin); freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
