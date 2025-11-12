#include<bits/stdc++.h>
using namespace std;
long long n=strlen(s),my_number[20];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[1000010];
	cin>>s;
	for(int i=0;i<n;i++){
		if(0<=s[i]-'0'&&s[i]-'0'<=9){
			my_number[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=my_number[i];j++) cout<<i;
	}
	return 0;
} 
