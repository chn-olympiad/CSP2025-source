//100+100+25+10=235pts
//Re:end of a dream
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=509;
int n,m,a[N],b[N];
char c[N];
int p[N];
bool check(){
	int now=0;
	for(int i=1;i<=n;i++){
		if(now>=b[i]||c[i]=='0') now++;
	}
	return (n-now)>=m;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=10){
		for(int i=1;i<=n;i++) p[i]=i;
		int ans=0;
		do{
			for(int i=1;i<=n;i++) b[i]=a[p[i]];
			if(check()) ans++;
		}while(next_permutation(p+1,p+n+1));
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
}
