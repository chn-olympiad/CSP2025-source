#include<bits/stdc++.h>
using namespace std;
int n,m,c[1010],j,g[1000];
char h[1010];
const int N=998244353;
bool t=true,can[1000],k[1000];
long long su=1,ans=0,use[1000];
map<long long,long long>mp;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	use[1]=1;
	for(int i=1;i<=n;i++){
		g[i]=i;
	}
	for(int i=1;i<=n;i++){
		cin>>h[i];
		if(h[i]='0'){
			t=false;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		mp[c[i]]++;
	}
	if(t){
		su=1;
	}
	for(int i=1;i<=n;i++){
		if(!can[c[i]]){
			k%=can;
			can[c[i]]=ture
		}
	}
	}else 
		do{
		for(int i=1;i<=n;i++){
		if(j>=c[g[i]]||h[i]=='0'){
			j++;
		}
	}	
	if(n-j>=m){
		ans++;
		ans%=N;
	}
		}
		while(next_permutation(g+1,g+1+n)){
		cout<<ans;	
		}
	}
	return 0;
}

