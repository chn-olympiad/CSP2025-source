#include<bits/stdc++.h>
using namespace std;
int n,ans,k,a[500006],s[500006],dp[500006];
vector<int> w[2500006];
int ef(int x,int y,int z){
	int dd=-1,l=1,r=w[z].size()-1;
	while(l<=r){
		int mid=l+r>>1;
		if(w[z][mid]>=x) dd=mid,r=mid-1;
		else l=mid+1; 
	}
	return dd;
}
int kd(){
	int z=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') z=z*10+c-'0',c=getchar();
	return z;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<=2e6+5e5;i++) w[i].push_back(-1);
	for(int i=1;i<=n;i++) a[i]=kd(),s[i]=(s[i-1]^a[i]),w[s[i]].push_back(i); 
	for(int i=1;i<=n;i++){
		int t=(k^s[i-1]);
		int wz=ef(i,n,t);
		dp[i]=max(dp[i],dp[i-1]);
		if(wz!=-1&&wz!=0) dp[w[t][wz]]=max(dp[w[t][wz]],dp[i-1]+1);		
	}
	cout<<dp[n];
	return 0;
}