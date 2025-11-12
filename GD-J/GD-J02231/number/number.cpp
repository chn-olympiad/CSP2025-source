#include<bits/stdc++.h>
using namespace std;
const int N = 15;
int m[N];
string inp;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin>>inp;
	for(int i = 0;i<inp.length();i++){
		if(!('0'<=inp[i]&&inp[i]<='9')) continue;
		m[inp[i]-'0']++;
	}
	
	bool flag_z = 1;
	for(int i = 9;i>=1;i--){
		if(m[i] <= 0) continue;
		flag_z = 0;
		for(int j = 1;j<=m[i];j++){
			cout<<i;
		}
	}
	
	if(flag_z) cout<<0;
	else{
		for(int i = 1;i<=m[0];i++){
			cout<<0;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
