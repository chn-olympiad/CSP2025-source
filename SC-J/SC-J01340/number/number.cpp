#include<bits/stdc++.h>
using namespace std;
const int N=1e6+6;
char s[N];
int b[10],l;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>s+1;
	l=strlen(s+1);
	int cnt=0;
	for(int i=1;i<=l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			b[s[i]-'0']++;
			cnt++;
		}
	}
	if(cnt==b[0]){
		cout<<0;
		return 0;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=b[i];j++)cout<<i;
	}
	return 0;
} 