#include <bits/stdc++.h>//#Shang4Shan3Ruo6Shui4
using namespace std;
string s;
int c[1000100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n = s.size();
	for(int i = 0;i < n;i++){
		if(s[i] == '0'){
			c[0]++;
		}
		else if(s[i] == '1'){
			c[1]++;
		}
		else if(s[i] == '2'){
			c[2]++;
		}
		else if(s[i] == '3'){
			c[3]++;
		}
		else if(s[i] == '4'){
			c[4]++;
		}
		else if(s[i] == '5'){
			c[5]++;
		}
		else if(s[i] == '6'){
			c[6]++;
		}
		else if(s[i] == '7'){
			c[7]++;
		}
		else if(s[i] == '8'){
			c[8]++;
		}
		else if(s[i] == '9'){
			c[9]++;
		}
	}
	for(int j = 9;j >= 0;j--){
		for(int k = 1;k <= c[j];k++){
			cout<<j;
		}
	}
	cout<<endl;
	return 0;
}
