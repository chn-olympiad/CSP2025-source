#include<bits/stdc++.h>
using namespace std;

int n,m;
string s;
int c[505],shu[505];

int dp[5005],a[5005];
int ma=0;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m>>s;
	for (int i=1;i<=n;i++){
		cin>>c[i];
		ma=max(ma,c[i]);
		dp[c[i]]++;
	}
	
	
	int x=1;
	bool f=0;
	for (int i=0;i<s.size();i++){
		shu[i+1]=x;
		if (s[i]=='0'){
			x++;
		}
		else{
			f=1;
		}
	}
	
	for (int i=1;i<=n;i++){
		a[shu[i]]++;
	}
	
	if (!f){
		int tot=1;
		for (int i=1;i<=n;i++){
			tot*=i;
		}
		cout<<tot;
		return 0;
	}
	
	int ans=1;
	
	for (int i=n;i>=1;i--){
		if (a[i]==1){
			continue;
		}
		else{
			int tot=1;
			for (int j=dp[i];j>=1;j--){
				tot*=j;
			}
			ans*=tot;
		}
	}
	
	cout<<ans;
	
	
	return 0;
}
