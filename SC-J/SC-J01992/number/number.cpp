#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int t=0,sl=0;
	cin>>s;
	for(int i=0;i<=s.length()-1;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++t]=s[i]-'0';
			sl++;
		}
	}
	sort(a+1,a+1+sl);
	for(int i=sl;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}