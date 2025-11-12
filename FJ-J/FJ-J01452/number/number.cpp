#include<bits/stdc++.h>
using namespace std;
string s;
long long b[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			b[s[i]-'0']++;
			//cout<<i<<" "<<s[i];
		}
	}
	//cout<<b[0];
	if(b[9]!=0){
		for(int i=1;i<=b[9];i++){
			cout<<int(9);
		}
	}
	if(b[8]!=0){
		for(int i=1;i<=b[8];i++){
			cout<<int(8);
		}
	}
	if(b[7]!=0){
		for(int i=1;i<=b[7];i++){
			cout<<int(7);
		}
	}
	if(b[6]!=0){
		for(int i=1;i<=b[6];i++){
			cout<<int(6);
		}
	}
	if(b[5]!=0){
		for(int i=1;i<=b[5];i++){
			cout<<int(5);
		}
	}
	if(b[4]!=0){
		for(int i=1;i<=b[4];i++){
			cout<<int(4);
		}
	}
	if(b[3]!=0){
		for(int i=1;i<=b[3];i++){
			cout<<int(3);
		}
	}
	if(b[2]!=0){
		for(int i=1;i<=b[2];i++){
			cout<<int(2);
		}
	}
	if(b[1]!=0){
		for(int i=1;i<=b[1];i++){
			cout<<int(1);
		}
	}
	if(b[0]!=0){
		for(int i=1;i<=b[0];i++){
			cout<<int(0);
		}
	}
	//cout<<b[0];
	return 0;
}
