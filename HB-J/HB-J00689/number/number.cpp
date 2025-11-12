#include<bits/stdc++.h>
using namespace std;
string s;
int book[100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<int(s.size());i++){
		if('0'<=s[i]&&s[i]<='9') book[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(book[i]){
			printf("%d",i);
			book[i]--;
		}
	}
	return 0;
}
