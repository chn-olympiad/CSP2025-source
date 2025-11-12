#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,n="";
	long long t[15]={0};
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(s[i]=='0'){
			t[0]++;
		}
		if(s[i]=='1'){
			t[1]++;
		}
		if(s[i]=='2'){
			t[2]++;
		}
		if(s[i]=='3'){
			t[3]++;
		} 
		if(s[i]=='4'){
			t[4]++;
		}
		if(s[i]=='5'){
			t[5]++;
		}
		if(s[i]=='6'){
			t[6]++;
		}
		if(s[i]=='7'){
			t[7]++;
		}
		if(s[i]=='8'){
			t[8]++;
		}
		if(s[i]=='9'){
			t[9]++;
		}
	}
	for(long long i=9;i>=0;i--){
		while(t[i]){
			n+=char(i+48);
			t[i]--;
		}
	}
	cout<<n;
	return 0;
}
