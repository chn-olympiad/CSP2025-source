#include <bits/stdc++.h>
using namespace std;
int sum[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(char i:s){
		if(i>='0'&&i<='9') {
			//cout<<i<<endl;
			sum[i-'0']++;
		}
	}
	for(int i=9;i>=0;i--) {
		while(sum[i]) {
			cout<<i;
			sum[i]--;
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
} 
