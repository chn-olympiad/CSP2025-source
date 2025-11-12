#include <bits/stdc++.h>
using namespace std;
int a[500000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	vector <vector <int> > dp(n+1,vector <int>(n+1));
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i][i]=a[i];
	}
	int c=0,t=1;
	if(a[1]==k){
		c++;
	}
	int kg=0;
	for(int i=2;i<=n;i++){
		kg=0;
		if(t!=i){
			for(int o=t;o<=i;o++){
				if(o==i&&a[i]==k&&kg==0){
					c++;
					t=i+1;
					kg=1;
				}else if(dp[o][i-1]^a[i]==k&&kg==0){
					c++;
					t=i+1;
					kg=1;
				}
				if(o!=i){
					dp[o][i]=dp[o][i-1]^a[i];
				}
			}
		}
	}
	cout<<c;
	return 0;
}
