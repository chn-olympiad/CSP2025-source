#include<cstdio>
#include<vector>
using namespace std;
vector<int>a;
vector<int>dp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	scanf("%d%d",&n,&k);
	a.resize(n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		bool b=false;
		for(int j=0;j<dp.size();j++){
			if((a[i]^dp[j])==k){
				b=true;
				break;
			}
			else dp[j]=dp[j]^a[i];
		}
		dp.push_back(a[i]);
		if(!b){
			if(a[i]==k){
				b=true;
			}
		}
		if(b){
			ans++;
			dp.clear();
		}
	}
	printf("%d",ans);
	return 0;
} 
