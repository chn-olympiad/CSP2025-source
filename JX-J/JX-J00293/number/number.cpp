#include<bits/stdc++.h>
using namespace std;
string a;char s[1000005];

bool cmp(char a,char b){
	return a>b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int l=a.size(),idx=0;
	for(int i=0;i<l;i++){
		if('0'<=a[i]&&'9'>=a[i]){
			s[idx++]=a[i];
		}
	}
	s[idx]='\0';
	sort(s,s+idx,cmp);
	for(int i=0;i<idx;i++){
		cout<<s[i];
	}
	
	return 0;
}
