#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000000];
int main(){
	freopen("number.in","r","std.in");
	freopen("number.out","w","std.out");
	cin>>s;
	int j=0;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[j]=s[i]-'0';
			j++;
		}
	}
	sort(a,a+j);
	for(int i=j-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}