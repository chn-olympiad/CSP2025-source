#include<bits/stdc++.h>
using namespace std;
int s[1000005]={0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int j=0;
	for(int i=0;i<a.length();i++){
		if('0'<=a[i]&&a[i]<='9'){
			s[j++]=a[i]-'0';
		}
	}
	sort(s,s+j);
	for(int i=j-1;i>=0;i--){
		cout<<s[i];
	}
	return 0;
}
