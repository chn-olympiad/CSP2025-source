#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	int a[10]={0};
	int fou=1;
	for(int i=0;i<len;i++){
		if('0'<=s[i] && s[i]<='9'){
			a[int(s[i])-48]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]){
			cout<<i;
			a[i]--;
		}
	}
	return 0;
} 
