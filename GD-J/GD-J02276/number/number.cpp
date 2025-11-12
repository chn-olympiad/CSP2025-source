#include<bits/stdc++.h>
using namespace std;


int n;
int num[20]; 
void h(){
	cout << "\n";
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin.tie(0),cout.tie(0);
	string s;
	cin >> s;
	for(int i = 0;i < s.size();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			num[s[i]-'0']++;
		}
	}
//	for(int i = 0;i <= 9;i++){
//		cout << i << ":" << num[i] << "\n";
//	}
//	h();
	for(int i = 9;i >= 0;i--){
		for(int j = num[i];j > 0;j--){
			cout << i;
		}
	}

	return 0;
}

