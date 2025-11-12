#include<bits/stdc++.h>
using namespace std;
int a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(long long i=0;s[i]!='\0';i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[(int)(s[i]-'0')]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(long long j=1;j<=a[i];j++){
			printf("%d",i);
		}
	}
	return 0;
}
