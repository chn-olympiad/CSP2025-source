#include<bits/stdc++.h>
using namespace std;
string s;
int x[10]; 
//REDEMPTION~
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		int c=s[i];
		if(c>='0'&&c<='9'){
			x[c-'0']++;
		}
	}
	if(x[1]==0&&x[2]==0&&x[3]==0&&x[4]==0&&x[5]==0&&x[6]==0&&x[7]==0&&x[8]==0&&x[9]==0){cout<<0<<endl;return 0;}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=x[i];j++){
			cout<<i;
		}
	}
	return 0;
}
