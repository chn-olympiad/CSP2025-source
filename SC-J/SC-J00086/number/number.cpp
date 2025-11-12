#include<iostream>
using namespace std;

int main(){
	freopen("number.out","w",stdout);
	freopen("number.in","r",stdin);
	char s[1000005];
	int a[10]={};
	cin>>s;
	for(int i=0;s[i]!='\0';i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		//cout<<i<<a[i]<<endl;
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}
} 