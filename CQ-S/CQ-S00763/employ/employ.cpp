#include <bits/stdc++.h>
using namespace std;
long long n,m,a[50005],ans,INF=998244353;
bool vis[50005],f=1;
string s;

void DFS(long long i,long long shi,long long cheng){
	if(i>n+1){
		return;
	}
	if(cheng>=m&&i==n+1){
		ans++;
		ans%=INF;
		return;
	}
	
	for(int j=1;j<=n;j++){
		if(vis[j]==0){
			vis[j]=1;
			if(!(shi<a[j])||s[i]=='0'){
				DFS(i+1,shi+1,cheng);
			}else if(s[i]=='1'){
				DFS(i+1,shi,cheng+1);
			}
			vis[j]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	s=' '+s;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(m==n){
		ans=n;
		for(int i=1;i<=n;i++){
			if(i!=1){
				ans*=n-i+1;
				ans%=INF;
			}
			if(s[i]!='1'||a[i]==0){
				f=0;
				break;
			}
		} 
		if(!f){
			cout << 0;
			return 0;
		}
		
	}
	DFS(1,0,0);
	cout << ans;
	return 0;
} 
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/
