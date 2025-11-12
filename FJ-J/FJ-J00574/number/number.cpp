#include<bits/stdc++.h>
using namespace std;

char num[]={'0','1','2','3','4','5','6','7','8','9'};
int temp[1000005],len;

bool big(int a,int b){
	return a>b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string str;
	cin>>str;
	for(int i=0;i<str.size();i++){
		for(int j=0;j<10;j++){
			if(str[i]==num[j]) temp[len++]=str[i]-'0';
		}
	}

	sort(&temp[0],&temp[len],big);
	for(int i=0;i<len;i++) cout<<temp[i];
	
	return 0;
}