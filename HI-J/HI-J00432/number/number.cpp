#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(void){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size(),cnt=0;
	for(int i=0;i<len;i++){
		if(int(s[i])<=57){
			cnt++;
			a[cnt]=int(s[i])-48;
		}
	}sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++) cout<<a[i];
	return 0;
}
