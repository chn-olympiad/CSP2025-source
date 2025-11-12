#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
char a[100010];
int b[100010],d=-1;
int sum=0;
int32_t main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);std::cout.tie(nullptr);
	std::cin>>s;
	for(int i=0;i<s.size();i++){
		sum=i;
		if(s[i]=='0') a[i]=0;
		else if(s[i]=='1') a[i]='1';
		else if(s[i]=='2') a[i]='2';
		else if(s[i]=='3') a[i]='3';
		else if(s[i]=='4') a[i]='4';
		else if(s[i]=='5') a[i]='5';
		else if(s[i]=='6') a[i]='6';
		else if(s[i]=='7') a[i]='7';
		else if(s[i]=='8') a[i]='8';
		else if(s[i]=='9') a[i]='9';
		else a[i]=' ';
	}
	for(int i=0;i<s.size();i++){
		if(a[i]!=' '){
			if(a[i]=='1') b[i]=1;
			if(a[i]=='2') b[i]=2;
			if(a[i]=='3') b[i]=3;
			if(a[i]=='4') b[i]=4;
			if(a[i]=='5') b[i]=5;
			if(a[i]=='6') b[i]=6;
			if(a[i]=='7') b[i]=7;
			if(a[i]=='8') b[i]=8;
			if(a[i]=='9') b[i]=9;
			if(a[i]=='0') b[i]=0;
		}else if(a[i]==' '){
			b[i]=-1;
		}
	}
	for(int i=1;i<s.size();i++){
		for(int j=0;j<s.size()-i;j++){
			if(b[j]<b[j+1]){
				swap(b[j],b[j+1]);
			}
		}
	}
	for(int i=0;i<s.size();i++){
		if(b[i]!=-1){
			cout<<b[i];
		}
	}
	return 0;
}
