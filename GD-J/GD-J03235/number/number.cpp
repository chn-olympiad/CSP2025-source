#include<iostream>
#include<cstring>
#include<algorithm>
#include<fstream>
using namespace std;
string s;
int num[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int tmp=0;
	for(int i=0;i<s.length();i++){
		if('0'<=s[i] and s[i]<='9'){
			num[tmp]=s[i]-'0';
			tmp++;
		}
	}
	sort(num,num+tmp);
	for(int i=tmp-1;i>=0;i--)cout<<num[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
