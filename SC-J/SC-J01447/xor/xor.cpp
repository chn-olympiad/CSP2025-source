#include<bits/stdc++.h>
using namespace std;
long long a[500002];
//int dp[500002];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,cnt=0,d=1,ans=0,num;
	bool o=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1||a[i]!=0) o=0;
	}
	if(o&&n>1000){//特殊情况 
		for(int i=1;i<=n;i++){
			if(a[i]==1) ans++;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cnt^=a[i];
		num=cnt;
		for(int j=d;j<i;j++){
			num^=a[j];
			if(num==k){
				//cout<<j+1<<" "<<i<<endl;
				//dp[i]++;
				ans++;
				d=i+1,cnt=0;
				break;
			}
		}
		if(cnt==k&&d<=i){
			//cout<<d<<" "<<i<<endl;
			//dp[i]++;
			ans++;
			d=i+1,cnt=0;
		}
	}
	cout<<ans;
	return 0;
} 