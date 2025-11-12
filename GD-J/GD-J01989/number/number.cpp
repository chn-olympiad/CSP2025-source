#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
int len;
string s;
int c[MAXN]; 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]=='0'){
			c[0]++;
		}
		if(s[i]=='1'){
			c[1]++;
		}
		if(s[i]=='2'){
			c[2]++;
		}
		if(s[i]=='3'){
			c[3]++;
		}
		if(s[i]=='4'){
			c[4]++;
		}
		if(s[i]=='5'){
			c[5]++;
		}
		if(s[i]=='6'){
			c[6]++;
		}
		if(s[i]=='7'){
			c[7]++;
		}
		if(s[i]=='8'){
			c[8]++;
		}
		if(s[i]=='9'){
			c[9]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=c[i];j++){
			cout<<i;
		}
	}
	return 0;
} 
