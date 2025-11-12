#include<bits/stdc++.h>
using namespace std;
const int N=505,P=998244353;
int n,m,s[N],c[N],minn=1,per[N];
char ch;
int PER(){
	for(int i=1;i<=n;i++) per[i]=i;int ans=0;
	do{
		int cnt=0;
		for(int i=1;i<=n;i++) if(!s[i]||c[per[i]]<=cnt) cnt++;
		if(n-cnt>=m) ans++;
	}while(next_permutation(per+1,per+1+n));
	return ans;
} 
int JC(){
	int ans=1;
	for(int i=1;i<=n;i++) ans=1ll*ans*i%P;
	return ans;
}
int ck(){
	if(!minn) return 0;
	for(int i=1;i<=n;i++) if(!c[i]) return 0;
	int ans=1;
	for(int i=1;i<=n;i++) ans=1ll*ans*i%P;
	return ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>ch,s[i]=ch-'0',minn=min(minn,s[i]);
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=10) cout<<PER();
	else if(n==m) cout<<ck();
	else cout<<0;
	return 0;
}
