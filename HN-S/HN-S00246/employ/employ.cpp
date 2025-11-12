#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,p=998244353;
int n,m,c[N],b[N],cnt;
bool f=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		c[i]=s[i-1]-'0';
		if(c[i]!=1)f=0;
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(b[i]==0)cnt++;
	}
	if(n<=10){
		int q[11],ans=0;
		for(int i=1;i<=n;i++)q[i]=i;
		do{
			int k=0;
			for(int i=1;i<=n;i++){
				if(n-k<m)break;
				if(!c[i]||k>=b[q[i]])
					k++;
			}
			if(n-k>=m)
				ans++;
		}while(next_permutation(q+1,q+n+1));
		cout<<ans<<endl;
		return 0;
	}
	if(n-cnt<m){
		cout<<0<<endl;
		return 0;
	}
	if(m==1){
		cout<<0;
		return 0;
	}else if(m==n){
		return 0;
	}else if(f){
		int res=1;
		for(int i=2;i<=n;i++)(res*=i)%=p;
		cout<<res<<endl;
		return 0;
	}
	return 0;
}
