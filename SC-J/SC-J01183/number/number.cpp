#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

char a[1000100]={0};

bool cmp(char x,char y){
	if(x>y){
		return true;
	}
	
	return false;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin>>s;
	
	int p=1;
	for(int i=0;i<s.length();i++){
		if((s[i]>='0')&&(s[i]<='9')){
			a[p]=s[i];
			p++;
		}
	}
	
	sort(a+1,a+p,cmp);
	
	for(int i=1;i<p;i++){
		cout<<a[i];
	}
	
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
