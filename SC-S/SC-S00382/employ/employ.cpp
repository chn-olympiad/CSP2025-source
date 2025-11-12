#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505;
int n,m,c[N],cnt,cnt1;
bool u[N];
string s;
void go(int w,int k){
	cnt1++;
	if(cnt1>1e8){
		cout<<cnt;
		exit(0);
	}
	if(n-w<m)return;
	if(k==n){
		cnt++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(u[i])continue;
		u[i]=1;
		int l=w;
		if(s[k]=='0')l++;
		else if(w>=c[i])l++;
		go(l,k+1); 
		u[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	go(0,0);
	cout<<cnt;
	return 0;
}