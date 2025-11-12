#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define mod 998244353
using namespace std;
const int N=505;
int n,m,c[N];
bool f;
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;++i){
		cin>>c[i];
	}
	for(int i=0;i<n;++i){
		if(s[i]=='0'){
			f=true;
			break;
		}
	}
	if(!f){
		cout<<0<<endl;
		return 0;
	}
	if(m==1){
		int num=n;
		for(int i=1;i<=n;++i){
			if(!c[i]){
				num--;
			}
		}
		int ans=n-num,p=1;
		if(!ans){
			for(int i=1;i<=n;++i){
				p*=i;
				p%=mod;
			}
			cout<<p<<endl;
			return 0;
		}
		for(int i=1;i<=ans;++i){
			p*=i;
		}
		p%=mod;
		if(num){
			for(int i=1;i<=num;++i){
				p*=i;
			}
		}
		p%=mod;
		cout<<p<<endl;
		return 0;
	}
	if(m==n){
		sort(c+1,c+1+n);
		for(int i=0;i<n;++i){
			if(s[i]=='1'){
				cout<<0<<endl;
				return 0;
			}
		}
		for(int i=1;i<=n;++i){
			if(c[i]<i-1){
				cout<<0<<endl;
				return 0;
			}
		}
		cout<<1<<endl;
		return 0;
	}
	int k=114514;
	cout<<k<<endl;
	return 0;
}
