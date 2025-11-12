#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000001],smax;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0; i<=s.length()-1; i++) {
		if(s[i]>='0'&&s[i]<='9') {
			int num=s[i];
			a[num-48]++;
			if(num>=smax) smax=num;
		}
	}
//	for(int i=0;i<=5;i++){
//		cout<<a[i];
//	}
	for(int i=smax;i>=0;i--){
		for(int j=1;j<=a[i];j++) cout<<i;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
	int num=s[0];
	cout<<num-48;
*/