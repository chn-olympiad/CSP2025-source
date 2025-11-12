#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int j = 0;
int flag;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len = s.size();
	for(int i = 0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			if(s[i]>='1'&&s[i]<='9'){
				flag = 1;}
			a[j] = s[i]-'0';
			j++;
			}
		}
		
	sort(a,a+j,greater<int>());
	if(flag!=1){
		cout<<0;
		return 0;}
	for(int i = 0;i<j;i++){
		cout<<a[i];
	}
	return 0;
	}

