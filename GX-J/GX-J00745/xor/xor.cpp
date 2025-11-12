#include <bits/stdc++.h>
using namespace std;
int xor_vec(vector<int>& vec){
	int x=vec[0];
	for(int i=1;i<vec.size();i++){
		x=x^vec[i];
	}
	return x;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	vector<int> vec(n);
	vector<int> now;
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>vec[i];
		now.push_back(vec[i]);
		if(xor_vec(now)==k){
			now={};
			sum++;
		}
	}
	cout<<sum;
}
