#include <bits/stdc++.h>
using namespace std;

const int N=505,mod=998244353;
int n,m,a[N],c[N];
string s;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	
	for(int i=1;i<=n;i++)a[i]=i;//初始化顺序
	int ans=0;
	do{
		int giveup=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(giveup<c[a[i]]&&s[i-1]=='1')cnt++;
			else giveup++;
		}
		if(cnt>=m)ans=(ans+1)%mod;
	}while(next_permutation(a+1,a+1+n));
	
	cout<<ans<<'\n';
	return 0;
}
