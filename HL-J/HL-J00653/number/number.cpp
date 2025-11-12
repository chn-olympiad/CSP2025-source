#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
string str;
vector<int>digit;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0,len=str.size();i<len;i++){
		if(str[i]>='0'&&str[i]<='9'){
			digit.push_back(str[i]-'0');
		}
	}
	sort(digit.begin(),digit.end());
	for(int i=digit.size()-1;i>=0;i--){
		printf("%d",digit[i]);
	}
	printf("\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
