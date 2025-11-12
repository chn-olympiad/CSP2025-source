#include<bits/stdc++.h>
using namespace std;

string s;
char a[1000007];

bool cmp(char a,char b){
	return a>b;
}

int main(){
	
	cin>>s;
	s=" "+s;
	int l=s.length();
	int j=1;
	for(int i=0;i<l;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[j]=s[i];
			j++;
		}
	}
	sort(a,a+l,cmp);
	cout<<a;
	
	
	return 0;
}
