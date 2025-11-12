#include<bits/stdc++.h>
using namespace std;

vector<int>num_;
vector<int>xor_;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int num,ans=0,i,ans_=0,k,n;
	num_.push_back(0);
	
	cin>>n>>k;
	for(i=0;i<=n;i++){
		cin>>num;
		num_.push_back(num);
		ans++;
	}
	
	for(i=1;i<=ans;i++){
		xor_.push_back(num_[i]^num_[i-1]);
		ans_++;
	}
	
	cout<<ans_/k;
	
	return 0;
}
