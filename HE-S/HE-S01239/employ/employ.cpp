#include <bits/stdc++.h>
#define int long long
using namespace std;
int c[1000];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;s=' '+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	bool f=1;
	for(int i=1;i<=n;i++){
		if(s[i]=='0') f=0;
	}
	if(f){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(c[i]==0) cnt++;
		}
		if(cnt){
			n-=cnt;
			n++;	
		}
		int ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*i%998244353;
		}
		cout<<ans<<'\n';
	}
	else{
		int ans=0;
		vector<int> num;
		for(int i=1;i<=n;i++){
			num.push_back(i);
		}
		do{
			int sum=0;
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(s[i]=='0') cnt++;
				else if(cnt>=c[num[i-1]]) cnt++;
				else sum++;
			}
			if(sum>=m) ans++;
		}while(next_permutation(num.begin(),num.end()));
		cout<<ans<<'\n';
	}
	return 0;
}
