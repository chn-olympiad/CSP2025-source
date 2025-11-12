#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

char a[1000010];
int n = 0;

bool cmp(char a,char b){
	return a>b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin>>s;
	
	for(int i = 0;i<s.size();i++){
		if('0'<=s[i] && s[i]<='9'){
			n++;
			a[n] = s[i];
		}
	}
	
	sort(a+1,a+n+1,cmp);
	
	for(int i = 1;i<=n;i++){
		cout<<a[i];
	}
	
	cout<<endl;
	
	return 0;
	
}