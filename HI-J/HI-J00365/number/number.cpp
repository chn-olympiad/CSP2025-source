#include<bits/stdc++.h>
using namespace std;

char s[1000001];
int num[11],k=0,sum;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(num,0,sizeof(num));
	cin >> s;
	
	for(int i=0;i<strlen(s);i++){
		if('9'<s[i] or '0'>s[i]){
			continue;
		}else{
			num[s[i]-'0'+1]++;
		}
	} 
	for(int i=10;i>=0;i--){
		for(int j=num[i];j>=1;j--){
			sum = sum*10 + i-1;
		}
	}
	cout << sum;
	
	return 0;
} 
