#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int t[25];
char a[1000001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>(a+1);
	int len=strlen(a+1);
	for(int i=1;i<=len;i++){
		if(a[i]>='0'&&a[i]<='9'){
			t[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=t[i];j++){
			cout<<i;
		}
	}
	return 0;
}
