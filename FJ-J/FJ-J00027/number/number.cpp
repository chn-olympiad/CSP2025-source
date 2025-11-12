#include<bits/stdc++.h>
using namespace std;
int shu[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int length=s.size();
	for(int i=0;i<=length;i++){
		if(s[i]=='0'){
			shu[0]++;
		}else if(s[i]=='1'){
			shu[1]++;
		}else if(s[i]=='2'){
			shu[2]++;
		}else if(s[i]=='3'){
			shu[3]++;
		}else if(s[i]=='4'){
			shu[4]++;
		}else if(s[i]=='5'){
			shu[5]++;
		}else if(s[i]=='6'){
			shu[6]++;
		}else if(s[i]=='7'){
			shu[7]++;
		}else if(s[i]=='8'){
			shu[8]++;
		}else if(s[i]=='9'){
			shu[9]++;
		}
	}
	for(int i=9;i>=0;i--){
		int j=0;
		while(j<shu[i]){
			cout<<i;
			j++;
		}
	} 
	return 0;
} 
