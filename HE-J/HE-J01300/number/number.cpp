#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
string s;
int a[1000001];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	int index=0;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[index]=s[i]-48;
			index++;
		}
	}
	sort(a,a+index);
	for(int i=index-1;i>=0;i--){
		cout<<a[i];
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
