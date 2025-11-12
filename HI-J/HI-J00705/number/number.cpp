#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[1000005];
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s+1;
	int len=strlen(s+1);
	for(int i=1;i<=len;i++){
		a[i]=s[i]-'0';
	}
	sort(a+1,a+1+len);
	int num=0;
	for(int i=len;i>=1;i--){
		num=a[i]+a[i+1]/10;
		cout<<num;
	}
	return 0;
}
