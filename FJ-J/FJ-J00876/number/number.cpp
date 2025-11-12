#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[100010]={0};
	int n[100010]={0};
	long long nums=0;
	cin>>s;
	for(long long i=0;i<strlen(s);++i){
		if(isdigit(s[i])){
			++nums;
			n[nums]=(int)s[i]-48;
		}
	}
	sort(n+1,n+1+nums,cmp);
	if(n[1]!=0)
		for(long long i=1;i<=nums;++i){
			cout<<n[i];
		}
	else cout<<0;
	return 0;
}