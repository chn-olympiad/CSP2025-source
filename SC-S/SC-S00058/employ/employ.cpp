#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[501];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int flag=1;
	getline(cin,s);
	getline(cin,s);
	for(int i=1;i<=n;++i)cin>>c[i];
	for(int i=0;i<n;++i){
		if(s[i]!='1'){
			flag=0;break;
		}
	}if(flag){
		int cnt=0;
		for(int i=1;i<=n;++i){
			if(c[i]!=1)cnt++;
		}
		if((n-cnt)>=m){
			long long p=1;
			for(int i=1;i<=n-cnt;++i){
				p*=i;
			}cout<<p<<endl;
			p%=998244353;
			int q=1;
			for(int i=cnt;i>=1;--i)q*=i;
			q%=998244353;
			cout<<q<<endl;
			p*=q;
			cout<<p%998244353;
		}else{
			
		}
	}else{
		if(m==1){
			int cnt=0;
			int l=1,r=1;
			for(int i=1;i<=n;++i){
				l*=i;
				l%=998244353;
				if(c[i]==0)cnt++;
			}
			n-=2;
			for(int i=1;i<=n;++i){
				r*=i;r%=998244353;
			}
			r*=cnt;
			r%=998244353;
			r*=(cnt-1);
			r%=998244353;
			l-=r;
			cout<<l%998244353;
		}
	}
	return 0;
} 

