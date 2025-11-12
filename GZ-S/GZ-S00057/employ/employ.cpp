//GZ-S00057 毕节七星关东辰实验学校 刘杰 
#include<bits/stdc++.h>
using namespace std;
const int MX=998244353;
int a[501],ans=0;string s;
int p[501],v[501];int n,m;
int jc(int w){
	int sum=1;
	for(int i=1;i<=w;i++){
		sum*=i;
		sum%=MX;
	}
	return sum;
}

void check(){
	int pao=0,lu=0;
	for(int i=1;i<=n;i++){
		int k=s[i-1]-'0';
		if(pao<a[p[i]]){
			if(k==1){
				lu++;
			}
			else{
				pao++;
			}
		}
		else{
			pao++;
		}
	}
	if(lu>=m){
		ans++;
	} 
	ans%=MX;
}
void dfs(int w){
	if(w>n){
		check();
	}
	else{
		for(int i=1;i<=n;i++){
			if(!v[i]){
				v[i]=1;
				p[w]=i;
				dfs(w+1);
				v[i]=0;
			}
		}
	}
}
void solve(){
	//get 20 pts
	dfs(1);
	cout<<ans<<endl;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=0;
	for(int i=0;i<n;i++){
		cnt+=(s[i]-'0');
	}
	if(cnt==n){
		// get 20 pts.
		cout<<jc(n)%MX;
	}
	else if(cnt==0){
		cout<<0;
	}
	else if(m==n){
		//get 4 pts.
		if(cnt!=0){
			cout<<0;
		}
		else{
			cout<<1;
		}
	}
	else{
		solve();
	}
	return 0;
}
