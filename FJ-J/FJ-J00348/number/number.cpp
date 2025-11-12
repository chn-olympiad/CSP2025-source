#include <bits/stdc++.h>
using namespace std;
string s;
int a[10],flag=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=10;i>=0;i--){
		if(i==0&&flag==0){
			cout<<0;
			break;
		}
		while(a[i]){
			printf("%d",i);
			a[i]--;
			flag++;
		}
	}
	return 0;
}
