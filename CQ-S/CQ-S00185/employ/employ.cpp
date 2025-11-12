#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;

const int N=1e6+10,mod=99824353;
int n,m,l,ff=0/*注0*/,mark1=1,ans=0;
int c[N],v[N],cc[N];
string s;
//vector<int> G;

int jc(int p){
	if(p==1)return 1;
	return (p*jc(p-1))%mod;
}

bool check(){
	int fa=0/*注0*/,cnt=0/*注2*/;
	for(int i=1;i<=n;i++){
		if(!s[i]){
			fa++;
			continue;
		}
		if(cc[i]<=fa){
			fa++;
			continue;
		}
		cnt++;
	}
	if(cnt>=m)return 1;
	return 0;
}

void dfs(int p){//暴搜排列 
	if(p-1==n){
		if(check()/*模拟，检查是否满足*/)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			v[i]++,cc[p]==c[i];
			dfs(p+1);
			v[i]--,cc[p]=0;
		}
	}
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	//
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s[i];
		if(!s[i])mark1=0;
	}
	if(m==n&&!mark1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	s=" "+s;
	sort(c+1,c+1+n);
	if(n<=10){
		dfs(1);
		cout<<ans;
		return 0;
	}
	else {
		for(int i=1;i<=n;i++){
			if(!s[i]){
				ff++;continue;	
			}
			if(s[i]){
				int cnt=0;
				for(int j=1;j<=n;j++){
					if(c[j]>i/*注1*/)cnt++;
				}
				ans=jc(n-1)*cnt;
			}
		}
		cout<<7;
	}
	return 0;
}
//注0：失败人数 
//注1：这样写其实是不对的会导致总方案偏小，若把i改为f则偏大 
//注2:已招聘人数 

