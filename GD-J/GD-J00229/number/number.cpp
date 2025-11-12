#include<iostream>
#include<cstring>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	long long int s[15]={0};
	cin>>a;
	for(char i:a){
		if(!(i>='a'&&i<='z')) s[i-'0']++;
	}
	for(int i=10;i>=0;i--){
		for(int j=s[i];j>0;j--) cout<<i;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
