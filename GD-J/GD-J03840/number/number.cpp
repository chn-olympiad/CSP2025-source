#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdin);
	cin.tie(0);
	int n[1000005],ai=0,count=0,i=0;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			n[ai]=s[i]-'0';
			ai++;
			if(n[ai]==0) count++;
		}
	}
	sort(n,n+ai);
	for(int j=ai-1;j>=0;j--){
		if(n[j]==0&&count!=0) count--;
		cout<<n[j];
	}
}
