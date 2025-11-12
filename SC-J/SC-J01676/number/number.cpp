#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],ans;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		char n=s[i];
		if('0'<=n&&n<='9')a[++ans]=n-'0';
	}
	sort(a+1,a+1+ans,cmp);
	for(int i=1;i<=ans;i++){
		printf("%d",a[i]);
	}
	return 0;
}