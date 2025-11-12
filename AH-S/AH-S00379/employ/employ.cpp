#include<bits/stdc++.h>
using namespace std;
long long fac(long long x){
	long long j=1;
	for(long long i=2;i<=x;i++){
		j=(j*i)%998244353;
	}
	return j;
}
int n,m;
string s;
int a[510];
bool v[510];
vector<int>vec;
int ans=0;
void dfs(int x){
	if(x>=n){
		int cnt=0;
		int h=0;
		for(int i=0;i<n;i++){
			if(cnt>=vec[i]){
				cnt++;
			}else if(s[i]=='0'){
				cnt++;
			}else{
				h++;
			}
		}
		
		if(h>=m)ans++;
	}
	for(int i=0;i<n;i++){
		if(v[i]==0){
			v[i]=1;
			vec.push_back(a[i]);
			dfs(x+1);
			v[i]=0;
			vec.pop_back();
		}
	}
}
void dfs2(int x,int cnt){
	if(x>=n){
		return;
	}
	for(int i=0;i<n;i++){
		if(v[i]==0){
			if(s[vec.size()]=='0'||cnt>=a[i]){
				cnt++;
			}else{
				ans=(ans+fac(n-vec.size()-1))%998244353;
				continue;
			}
			v[i]=1;
			vec.push_back(a[i]);
			dfs2(x+1,cnt);
			v[i]=0;
			if(s[vec.size()]=='0'||cnt>=a[i]){
				cnt--;
			}
			vec.pop_back();
		}
	}
}
void dfs3(int x){
	if(x>=n){
		return;
	}
	for(int i=0;i<n;i++){
		if(v[i]==0){
			
			if(s[vec.size()]=='0'||cnt>=a[i]){
				continue
			}
			v[i]=1;
			vec.push_back(a[i]);
			dfs2(x+1,cnt);
			v[i]=0;
			vec.pop_back();
		}
	}
}
int main(){
	memset(v,0,sizeof(v));
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int cnt=0;
	for(char t:s){
		if(t=='1')cnt++;
	}
	if(cnt<m){
		cout<<0;
		return 0;
	}
	bool flag=1;
	int cnt2=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(m==n&&a[i]==0){
			cout<<0;
			return 0;
		}
		if(!a[i]){
			flag=0;
			cnt2++;
		}
	}
	if(cnt2<m){
		cout<<0;
		return 0;
	}
	if(cnt==n&&flag){
		cout<<fac(n);
		return 0;
	}
	if(n<=11){
		dfs(0);
		cout<<ans%998244353;
		return 0;
	}
	if(m==n){
		dfs3();
		cout<<ans%998244353;
	}
	if(m==1){
		dfs2(0,0);
		cout<<ans%998244353;
		return 0;
	}
	cout<<0;
	return 0;
}

