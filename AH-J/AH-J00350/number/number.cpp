#include<bits/stdc++.h>
using namespace std;
string s;
char a[1000010];
long long xh=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long n=s.size();
	for(long long i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[xh]=s[i];
			xh++;
		}
	}
	sort(a,a+xh,greater<char>());
	for(long long i=0;i<xh;i++){
		cout<<a[i];
	}
	return 0;	
}
