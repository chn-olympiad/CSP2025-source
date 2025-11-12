#include<bits/stdc++.h>
using namespace std;

string s;
int a[1000005],x,k;

bool cmp(int m,int n){
	return m>n;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	x=s.length();
	for(int i=0;i<x;i++){
		if(s[i]>='0'&&s[i]<='9') a[++k]=int(s[i]-'0');
	}
	sort(a+1,a+k+1,cmp);
	if(a[1]==0) cout<<0;
	else{
		for(int i=1;i<=k;i++) cout<<a[i];
	}
	return 0;
} 
