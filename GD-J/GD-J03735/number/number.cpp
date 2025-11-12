#include<bits/stdc++.h>
using namespace std;
string s;
int i,j;
int q[20];
//#Shang4Shan3Ruo6Shui4
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(i = 0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			q[s[i]-48]++;
		}
	}
	for(i = 9;i>=0;i--){
		for(int j = 1;j<=q[i];j++){
			cout<<i;
		}
	}
	return 0;
}
