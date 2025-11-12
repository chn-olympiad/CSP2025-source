#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int w[5005],a[5005];
long long dp[50005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>w[i];
		a[i]=a[i-1]+w[i];
	}
	sort(w+1,w+n+1);
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(w[3]*2<w[1]+w[2]+w[3])cout<<1;
		else cout<<0;
	}
	if(n==4){
		if(w[4]*2<w[1]+w[2]+w[3]+w[4]){
			if(w[3]*2<w[1]+w[2]+w[3]){
				if(w[4]*2<w[2]+w[3]+w[4]){
					cout<<3;
				}
				else cout<<2;
			}
			else {
				if(w[4]*2<w[2]+w[3]+w[4])cout<<2;
				else cout<<1;
			}
		}
		else cout<<0;
		return 0;
	}
	
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			if(a[j+i-1]-a[j-1]>2*w[j+i-1])ans++; 
		}
	}
	cout<<ans;
	return 0;
}
