#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int cnt=0;
	int len=s.size();
	int str[len];
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			str[cnt]=s[i]-'0';
			cnt++;	
		}
	}
	for(int i=0;i<cnt;i++){
		for(int j=0;j<i;j++){
			if(str[i]>str[j]){
				int t=str[i];
				str[i]=str[j];
				str[j]=t;
			}
		}
	}
	for(int i=0;i<cnt;i++){
		cout<<str[i];
	}
	return 0;
} 
