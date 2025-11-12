#include<iostream>
#include<string>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.length();
	if(l==1){
		cout<<s;
		return 0;
	}else{
		int b[10]={};
		for(int i=0;i<l;i++){
			if(s[i]>='0' && s[i]<='9'){
				b[s[i]-'0']++;
			}
		}
		for(int i=9;i>=0;i--){
			for(int j=0;j<b[i];j++){
				cout<<i;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
