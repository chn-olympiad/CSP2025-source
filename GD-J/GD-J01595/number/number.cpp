#include <bits/stdc++.h>
using namespace std; 
char a[1000005];
int x[15]; 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	int cnt=0;
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt++;
			a[cnt]=s[i];
		}
	}
	for(int i=1;i<=cnt;i++){
		int y=a[i]-'0';
		x[y]++;
	}
	string ans="";
	for(int i=9;i>=0;i--){
		while(x[i]!=0){
			cout<<i;
			x[i]--;
		}
	}
	return 0;
}
