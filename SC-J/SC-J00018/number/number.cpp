#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string s;
long long a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<(int)s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	if(a[9]==0&&a[8]==0&&a[7]==0&&a[6]==0&&a[5]==0&&a[4]==0&&a[3]==0&&a[2]==0&&a[1]==0){
		printf("0");
		return 0;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			printf("%d",i);
		}
	}
	return 0;
}