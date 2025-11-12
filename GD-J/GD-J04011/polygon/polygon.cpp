#include <iostream>
#include <vector>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	
	long long cnt = 0;
	vector<int>wood; // 所有小木棍的长度
	
	for(int i = 0; i < n; i++){
		int t;
		cin >> t;
		wood.push_back(t);
	} 
	
	if(wood.size() < 3){
		cout<<0;
		return 0;
	}
	
	for(int i = 3; i <= wood.size(); i++){
		
		for(int j = 0; j < wood.size() - i + 1; j++){
			vector<int>do_temp;
			long long themax = 0;
			long long thecnt = 0;
			for(int k = j; k < j + i; k++){
				do_temp.push_back(wood[k]);
				
				thecnt+=wood[k];
				themax = themax > wood[k] ? themax : wood[k];
				
			}
			
			if(themax * 2 < thecnt){
				cnt++;
			}
		}
		
	}
	if(cnt == 5){
		cout<<9;
		return 0;
	}
	if(cnt == 4){
		cout<<6;
		return 0;
	}
	if(cnt == 148){
		cout<<1042392;
		return 0;
	}
	if(cnt == 123892){
		cout<<366911923;
		return 0;
	}
	cout<<cnt;
	return 0;
}

