#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m; //横竖 
	cin>>n>>m;
	
	vector<int> nums;
	for(int i = 0;i < n*m;i++){
		int k = 0;
		cin>>k;
		nums.push_back(k);
	}
	int score = nums[0];
	sort(nums.begin(),nums.end());
	reverse(nums.begin(),nums.end());
	
	for(int i = 0;i < n*m;i++) cout<<nums[i]<<" ";
	cout<<endl;

	int p = 0;
	for(int i = 0;i < nums.size();i++){
		if(nums[i] == score){
			p = i + 1;
			cout<<p<<endl;
			break;
		}
	}
	//int n,m;有n行m列 1列有n个 1行有m个 
	int i = p,lie = 0,hang = 0;
	int cnt = 1;
	while(true){
		if(i == 0) cnt--;
		if(i < n){
			break;
		}
		cnt++;
		i = i - n;
	}
	lie = cnt;hang = p - ((cnt-1) * n);
	if(cnt % 2 == 0){
		hang = n+1 - hang;
	}
	cout<<lie<<" "<<hang;
	return 0;
}

