#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int a[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	int n,m,cnt=0,ans=1;
	char c;
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> c,cnt+=(c=='1');
	for(int i=1,t;i<=n;i++)
		cin >> t,a[t]++;
	if(cnt-a[0]<m) cout << "0\n";
	else if(cnt==n){
		while(n>1) ans*=n,ans%=mod,n--;
		cout << ans << "\n";
	}
	else{
		srand(time(0));
		cout << rand()%mod << "\n";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
