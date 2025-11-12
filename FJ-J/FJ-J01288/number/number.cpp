#include<bits/stdc++.h>
using namespace std;
string S;
int Nums[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> S;
	for(int i=0;i<S.size();i++){
		if(S[i]>='0' && S[i]<='9'){
			Nums[S[i]-'0']++;
		} 
	}
	for(int i=9;i>=0;i--){
		while(Nums[i]--){
			cout << i;
		}
	}
	return 0;
} 
