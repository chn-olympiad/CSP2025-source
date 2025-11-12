#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pr pair<int,int>
#define F first
#define S second
int n,k,s[500005],a[500005],cnt,ans,dp[1100007];
priority_queue<pr,vector<pr >,greater<pr > > q,qc;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i],s[i]=s[i-1]^a[i];
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i-1;j++){
			int pd=s[i]^s[j];
			if(k==pd){
				pr x;
				x.F=i;
				x.S=j+1;
				qc.push(x);
				q.push(x);
			}
		}
	}
//	while(!qc.empty()){
//		pr t=qc.top();
//		qc.pop();
//		cout<<t.F<<" "<<t.S<<"\n";
//	}
	for(int i=1;i<=n&&!q.empty();i++){
		priority_queue<int> ik;
		while(i==q.top().F&&!q.empty()){
			pr t=q.top();
			q.pop();
			ik.push(t.S);
//			cout<<t.S<<"_"<<t.F<<"\n";
//			cout<<dp[i]<<" "<<i<<"\n";
		}
		while(!ik.empty()){
			dp[i]=max(dp[i],dp[ik.top()]+1);
			ik.pop();
		}
		dp[i]=max(dp[i],dp[i-1]);
		ans=max(ans,dp[i]);
//		cout<<dp[i]<<" "<<i<<"\n";
	}
	cout<<ans;
	return 0;
}//#Shang4Shan3Ruo6Shui4
