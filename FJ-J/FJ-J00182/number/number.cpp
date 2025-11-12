#include<bits/stdc++.h>

using namespace std;

int main(){

	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	string c;
	cin>>c;
	int ct[10]={0};
	
	for(char i:c){
		if('0'<=i&&i<='9'){
			ct[i-'0']++;
		}
	}
	
	for(int i=9;i>=0;i--){
		for(int j=0;j<ct[i];j++){
			cout<<i;
		}
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}

