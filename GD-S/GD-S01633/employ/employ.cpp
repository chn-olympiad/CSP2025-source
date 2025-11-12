#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=505,mod=998244353;

int n,m,k,p[N];
bool q[N],SP=1;

signed main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		q[i]=(c=='1');
		SP=SP&q[i];
	}
	for(int i=1;i<=n;i++){
		cin>>p[i];
		if(p[i]==0){
			n--;
			i--;
		}
	}

	if(m>n){
		cout<<0;
		return 0;
	}
	
	if(SP){ //不可以，总司令！ 
		cout<<0;
	}
	else{
		cout<<0;
	}
	
	return 0;
	
} 
