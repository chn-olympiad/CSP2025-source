#include<iostream>
#include<string>
using namespace std;
string s;
int num[14];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			int aa=s[i]-'0';
			num[aa]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=num[i];j++){
			cout<<i;
		}
	}
	
	
	
	return 0;
	
}
