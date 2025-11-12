#include<bits/stdc++.h>
using namespace std;
int n,m,c[510],b[510],cnt,ans;
char ch;
bool flag=1,a[510];
void solve(){
	for(int i=1;i<=n;i++){
		b[i]=i;
	}
	do{ 
		cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0||c[b[i]]<=cnt){
				cnt++;
			}
		}
		if(n-cnt>=m)ans++;
	}while(next_permutation(b+1,b+n+1));
	cout<<ans<<endl;
}
void solve2(){
	
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ch;
		a[i]=ch-'0';
		if(ch-'0'!=1)flag=0;
	}
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n<=18){
		solve();
	}
	if(flag){
		solve2();
	}
	return 0;
}
