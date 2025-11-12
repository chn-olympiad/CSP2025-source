#include<bits/stdc++.h>

using namespace std;

string in;
int instrlen;
int looptimes;
int numlist[20];
bool is_zero;

int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	//in
	cin >> in;
	instrlen = in.size();
	
	//list
	for(int i = 0 ; i < instrlen ; i++){
		if(in[i] >= '0' && in[i] <= '9'){
			numlist[in[i]-'0']++;
		}
	}
	
	//out
	for(int i = 9 ; i >= 0 ; i--){
		looptimes = numlist[i];
		
		//zero out
		if(i == 0 && !is_zero){
			cout << 0;
			return 0;
		}
		
		//only zero?
		if(looptimes){
			is_zero  = true;
		}
		
		for(int j = 0 ; j < looptimes ; j++){
			cout << i;
		}
	}
	
	return 0;
}
