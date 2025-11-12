#include <bits/stdc++.h>

using namespace std;
int b[1000100];
string s;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >>s;
	long long index=0;
	for(int i=0;i<=s.length();i++){
		int a=s[i]-0;
		if(a>=48&&a<=57){
			b[index++]=a-48;
		}
	}
	sort(b,b+index,cmp);
	for(int i=0;i<index;i++){
		cout <<b[i];
	}
	return 0;
}