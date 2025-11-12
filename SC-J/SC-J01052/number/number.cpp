#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s = "";
	string nd = "";
	cin>>s;
	int a[15] = {0};
	int n = s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=a[i];j>0;j--){
			nd+=i+'0';
		}
	}
	cout<<nd;
	return 0;
} 