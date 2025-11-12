#include<bits/stdc++.h>
using namespace std;
string s;
int n,cnt[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if('0'<=s[i]&&s[i]<='9'){
			cnt[s[i]-'0']++;
		}
	}
	for(int i=9,j;i>=0;i--){
		j=cnt[i];
		while(j--){
			printf("%c",i+'0');
		}
	}
	return 0;
}
