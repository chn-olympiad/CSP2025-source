#include<bits/stdc++.h>
using namespace std;
string s;
long long flag[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long i=0;
	while(i<s.size()){
		if(s[i]=='0'){
			flag[0]++;
		}else if(s[i]=='1'){
			flag[1]++;
		}else if(s[i]=='2'){
			flag[2]++;
		}else if(s[i]=='3'){
			flag[3]++;
		}else if(s[i]=='4'){
			flag[4]++;
		}else if(s[i]=='5'){
			flag[5]++;
		}else if(s[i]=='6'){
			flag[6]++;
		}else if(s[i]=='7'){
			flag[7]++;
		}else if(s[i]=='8'){
			flag[8]++;
		}else if(s[i]=='9'){
			flag[9]++;
		}
		i++;
	}
	for(long long i=9;i>=0;i--){
		while(flag[i]--){
			cout<<i;
		}
	}
	return 0;
}
