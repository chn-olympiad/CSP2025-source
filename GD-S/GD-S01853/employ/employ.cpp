#include<bits/stdc++.h>
using namespace std;
int n,m,s[512],c[512],a[512],x,tot;
bool f[512];
void DFS(int id){
	if(id==n+1){
		int cnt1 = 0,cnt2 = 0;
		for(int i = 1;i<=n;i++){
			if(s[i]==1&&cnt1<c[a[i]])cnt2++;
			else cnt1++;
		}
		if(cnt2>=m)tot++;
	}
	for(int i = 1;i<=n;i++){
		if(f[i])continue;
		f[i] = 1;
		a[id] = i;
		DFS(id+1);
		f[i] = 0;
	}
	return ;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin>>n>>m;
	char ch;
	bool f = 0;
	for(int i = 1;i<=n;i++){
		cin>>ch;
		s[i] = ch-'0';
		if(!s[i])f = 1;
	}
	if(!f){
		long long x = 1;
		for(long long i = 1;i<=n;i++)x = x*i%998244353;
		cout<<x;
		return 0;
	}
	for(int i = 1;i<=n;i++)cin>>c[i];
	DFS(1);
	cout<<tot;
	return 0;
}

