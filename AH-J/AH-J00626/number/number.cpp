#include<bits/stdc++.h>
using namespace std;
string a;
int t[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int len=a.size();
	for(int i=0;i<len;i++){
		if(a[i]>='0'&&a[i]<='9')t[a[i]-'0']++;
	}
	bool flag=1;
	for(int i=9;i>=0;i--){
		if(i!=0&&t[i]!=0){
			flag=0;
		}
		if(flag&&i==0){
			cout<<0;
			return 0;
		}
		for(int j=1;j<=t[i];j++) cout<<i;
	}
	return 0;
}
