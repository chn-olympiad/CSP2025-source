#include<bits/stdc++.h>
using namespace std;
string s;
char a[1000005];
long long xb=1;
bool cmp(char x,char y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[xb]=s[i];
			xb++;
		}
	}
	sort(a+1,a+xb,cmp);
	for(long long i=1;i<xb;i++){
		cout<<a[i];
	}
	return 0;
}
