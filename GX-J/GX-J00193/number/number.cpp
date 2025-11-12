#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string s;
int a[1000005],cnt;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(auto ch:s){
		if(ch>='0'&&ch<='9')a[++cnt]=ch-'0';
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		cout<<a[i];
	}
	return 0;
}
