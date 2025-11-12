#include <bits/stdc++.h>
using namespace std;
string s;
long long int n[10];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	bool check=false;
	for(int i=0;i<s.length();i++){
		if(s[i]=='0') n[0]++;
		else if(s[i]=='1') n[1]++,check=true;
		else if(s[i]=='2') n[2]++,check=true;
		else if(s[i]=='3') n[3]++,check=true;
		else if(s[i]=='4') n[4]++,check=true;
		else if(s[i]=='5') n[5]++,check=true;
		else if(s[i]=='6') n[6]++,check=true;
		else if(s[i]=='7') n[7]++,check=true;
		else if(s[i]=='8') n[8]++,check=true;
		else if(s[i]=='9') n[9]++,check=true;
	}
	if(check){
		for(int i=9;i>=0;i--){
			for(int j=1;j<=n[i];j++){
				cout<<i;
			}
		}
	}
	else{
		cout<<0;
	}
	
	return 0;
}
