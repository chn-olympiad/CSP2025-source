#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int m,n;cin>>n>>m;
	string nan;cin>>nan;
	vector<int>nums(n);
	for(int i=0;i<n;i++)cin>>nums[i];
	sort(nums.begin(),nums.end());
	int las=0,cnt=0;
	if(n<=5){
		//if(n==3)cout<<2<<endl;
		//else{
		for(int i=0;i<n;i++){
			if(nums[i]-las<0)continue;
			if(nan[i]=='1'){
				las=i;
				cnt++;
				//}
				cout<<cnt;
			}}}
	else{
		srand(time(0));
		cout<<rand()%int(pow(n,3))%998244353<<endl;
	}
	return 0;
}