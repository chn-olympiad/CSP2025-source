#include<bits/stdc++.h>
using namespace std;
char a[100005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int sum=0;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='1' && s[i]<='9'){
			sum++;
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[i]=s[i];
		} else {
			continue;
		}
	}
	sort(a,a+s.size());
	for(int i=s.size()-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
} 