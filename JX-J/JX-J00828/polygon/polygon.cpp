#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
vector<int>v,su,dp,np;
int n,l,m;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.ans","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<3;i++)np.push_back(0);
	v.push_back(0);dp.push_back(0);su.push_back(0);
	for(int i=1;i<=n;i++){
        scanf("%d",&l);
        v.push_back(l);
	}
	sort(v.begin(),v.end());
	for(int i=1;i<=n;i++){
        su.push_back(su[i-1]+v[i]);
        dp.push_back(max(dp[i-1], v[i]) );
	}
	for(int i=3;i<=n;i++){
	    for(int j=1;j<i-3;j++){
            if(su[i]-v[i]>dp[i])m++;
	    }
        np.push_back(m+np[i-1]);
        //cout<<m;
	}
    cout<<np[n];
    return 0;
}
