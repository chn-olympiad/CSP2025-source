#include<bits/stdc++.h>

using namespace std;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	string s;
	cin>>s;
	
	if(s.size() == 1) cout<<s;
	else{
		long long num[10] = {0}, sum = 0;
		for(int i = 0; i<s.size(); i++){
			if(s[i] >= '0' && s[i]<='9'){
				int m = s[i]-'0';
				num[m]++;
			}
		}
		
		for(int i = 9; i>=0; i--){
			for(int j = 1; j<=num[i]; j++)
				cout<<i;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
