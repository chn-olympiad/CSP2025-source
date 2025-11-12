#include<bits/stdc++.h>
using namespace std;

const int MAXS=1e6+100;

string s;
int a[MAXS];
int cnt=0;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(a,0,sizeof(a));
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0') a[++cnt]=0;
		if(s[i]=='1') a[++cnt]=1;
		if(s[i]=='2') a[++cnt]=2;
		if(s[i]=='3') a[++cnt]=3;
		if(s[i]=='4') a[++cnt]=4;
		if(s[i]=='5') a[++cnt]=5;
		if(s[i]=='6') a[++cnt]=6;
		if(s[i]=='7') a[++cnt]=7;
		if(s[i]=='8') a[++cnt]=8;
		if(s[i]=='9') a[++cnt]=9;
	}
	sort(a+1,a+1+cnt);
	for(int i=cnt;i>=1;i--){
		printf("%d",a[i]);
	}
	return 0;
} 
