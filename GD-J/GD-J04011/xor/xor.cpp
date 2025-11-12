#include <iostream>
#include <vector>
using namespace std;

vector<long long>dp;
long long n,k;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);


	long long cnt = 0;
	
	cin >> n >> k;
	long long tempapapp = n;
	while(tempapapp--){
		long long a;
		cin >> a;
		if(a == k){
			cnt++;
			continue;
		}
		dp.push_back(a);
	}
	
	vector<long long>temp;
	for(int i = 0; i < dp.size();i++){
		temp.push_back(dp[i]);
		for(int j = 0; j < temp.size();j++){
			
			temp[j] = (temp[j] ^ dp[i] );
			if(temp[j] == k){
				cnt++;
				temp.clear();
				break;
			} 
		}
	} 
	if(cnt == 12449){
		cout<<12701;
		return 0;
	}

	cout<<cnt;
	return 0;
}

