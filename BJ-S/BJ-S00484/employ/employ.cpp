#include<bits/stdc++.h>
#define int long long 
using namespace std;
bool a[505];
int c[505],p[505];
int mod=998244353;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char ch;
		cin>>ch;
		if(ch=='1') a[i]=1;
		p[i]=i;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0) sum++;
	}
	int ans=0;
	do{
		int now=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(now<c[p[i]]){
				if(a[i]) cnt++;
				else now++;
			}else now++;
		}
		if(cnt>=m) ans++,ans%=mod;
	}while(next_permutation(p+1,p+1+n));
	cout<<ans;
	return 0;
}
