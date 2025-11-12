#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
string s;
int a[1000005]={0},ans=0,num=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9) a[++ans]=s[i]-'0';
	}
	sort(a+1,a+ans+1);
	for(int i=ans;i>=1;i--){
		printf("%d",a[i]);
	}
	return 0;
} 
