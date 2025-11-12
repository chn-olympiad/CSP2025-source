#include<bits/stdc++.h>
using namespace std;
const int mn = (1<<18)+17;
long long f[mn][20];
long long mod = 998244353;
int s[22];int c[22];
int cal(int x){
	int cnt = 0;
	while(x){
		if(x%2)cnt++;
		x/=2;
	}
	return cnt;
}
map<pair<int,int>,bool> ins;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		char op;
		cin>>op;
		if(op == '0')s[i] = 0;
		else s[i] = 1;
	
	}
	for(int i = 1;i <= n;i++){
		cin>>c[i];
	}
	int ALL = (1<<n)-1;
	queue<pair<int,int>> q;
	for(int i = 1;i <= n;i++){
		f[(1<<(i-1))][min(s[1],c[i])] = 1;
		q.push({(1<<(i-1)),min(s[1],c[i])});
		//cout<<(1<<(i-1))<<endl;
	}
	long long ans = 0;
	while(!q.empty()){
		pair<int,int> u = q.front();
		q.pop();
		int st = u.first,now = u.second;
		int cc = cal(st);
		//cout<<st<<" "<<now<<" "<<f[st][now]<<endl;
		if(st == ALL&&now>=m){
			ans+=f[st][now];
			ans%=mod;
			continue;
		} 
		for(int i = 1;i <= n;i++){
			if(((st>>(i-1))&1) == 0){
			   // cout<<st<<" "<<i<<" "<<cc-now<<endl; 
				if(cc-now<c[i]&&s[cc+1] == 1){
					//cout<<"ok:"<<st<<" "<<i<<" "<<cc-now<<endl; 
					f[st|((1<<(i-1)))][now+1] += f[st][now];
					f[st|((1<<(i-1)))][now+1] %= mod;
					if(!ins[{st|((1<<(i-1))),now+1}])q.push({st|((1<<(i-1))),now+1});
					ins[{st|((1<<(i-1))),now+1}] = 1;
				}
				else{
					f[st|((1<<(i-1)))][now] += f[st][now];
					f[st|((1<<(i-1)))][now] %= mod;
					if(!ins[{st|((1<<(i-1))),now}])q.push({st|((1<<(i-1))),now});
					ins[{st|((1<<(i-1))),now}] = 1;
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 
