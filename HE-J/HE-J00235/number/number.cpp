#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int sum1=0;
	char sum[1000000];
	for(int i=0;s[i]!='\0';i++){
		sum1++;
	}
	if(sum1==1){
		cout<<s;
	}
	else if(sum1==2){
		for(int i=0;i<=2;i++){
			if(s[i]>='0'&&s[i]<='9'){
				if(s[1]>s[0]){
					cout<<s[1]<<s[0];
				}else{
					cout<<s[0]<<s[1];
				}
			}
		}
	}
	else{
		for(int i=0;s[i]!='\0';i++){
			if(s[i]>='0'&&s[i]<='9'){
			 	sum[i]++;
			}
		}
	}
	return 0;
}
