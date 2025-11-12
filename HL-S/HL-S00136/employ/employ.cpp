#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,giveup=0;
	long long int ans=1;
	char s[510];
	int c[510],sor[510];
	cin>>n,m;
	for (int i=1;i<=n;i++){
		cin>>s[i];
	}
	for (int i=1;i<=n;i++){
		cin>>c[i];
		sor[i]=c[i];
	}
	sort(sor,sor+n);
	for (int i=1;i<=n;i++){
		if (s[i]=='0'){
			giveup++;
		}
		if (giveup>=sor[i]){
			sor[i]=0;
			giveup++;
		}
		else if (sor[i]!=0 and s[i]=='1'){
			ans++;
		}
	}
	cout<<ans%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
