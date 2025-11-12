#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w"stdout);
	string s,temp;
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++){
		if(!(s[i]>='a'&&s[i]<='z')){
			temp+=s[i];
		} 
	}
	int lentemp=temp.length();
	for(int i=0;i<lentemp;i++){
		a[i]=temp[i]-'0';
	}
	sort(a,a+lentemp,greater<int>());
	for(int i=0;i<lentemp;i++){
		cout<<a[i];
	}
	return 0;
} 
