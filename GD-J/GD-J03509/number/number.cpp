#include <bits/stdc++.h>
using namespace std;
string s;
int a[15];
bool flag=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(i==0&&!flag) {
			cout<<0;
			break;
		}
		if(a[i]) flag=1;
		while(a[i]>0){
			a[i]--;
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
