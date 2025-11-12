#include<bits/stdc++.h>
using namespace std;

string s;
int a[1000002];
bool cmp(int a,int b){
	return a>b;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >>s;
	int t=0;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(int(s[i])>=48&&int(s[i])<=57){
			a[t]=int(s[i])-48;
			t++;
		}
	}
	sort(a,a+t,cmp);
	for(int i=0;i<t;i++){
		cout <<a[i];
	}
	return 0;
}
