#include <iostream>
#include <vector>
using namespace std;
vector<int>v,dp;
int n,k,a,t=0,cnt=0;
int main(){
	freopen("xor2.in","r",stdin);
	freopen("xor1.ans","w",stdout);
	scanf("%d",&n);scanf("%d",&k);
	v.push_back(0);dp.push_back(0);
	for(int i=1;i<=n;i++){
		scanf("%d",&a);v.push_back(a);
		dp.push_back(v[i]^dp[i-1]);//

		//cout<<dp[i];
	}

	for(int i=1;i<=n;i++){// from 1 to i,i+1 to n
		if(k==(dp[i]^t) ){
                //cout<<dp[i-1]<<' ';
			t=dp[i];
			cnt++;
		}
	}


	cout<<cnt;
    return 0;
}
