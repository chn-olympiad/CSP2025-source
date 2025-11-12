#include<bits/stdc++.h>
using namespace std;
int n,num[15];
string a;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	n=a.length();
	for(int i=1;i<=n;i++){
		if(a[i]=='0') num[0]++;
		else if(a[i]=='1') num[1]++;
		else if(a[i]=='2') num[2]++;
		else if(a[i]=='3') num[3]++;
		else if(a[i]=='4') num[4]++;
		else if(a[i]=='5') num[5]++;
		else if(a[i]=='6') num[6]++;
		else if(a[i]=='7') num[7]++;
		else if(a[i]=='8') num[8]++;
		else if(a[i]=='9') num[9]++;
	}
	for(int j=1;j<=num[9];j++){
		cout<<9;
	}
	for(int j=1;j<=num[8];j++){
		cout<<8;
	}
	for(int j=1;j<=num[7];j++){
		cout<<7;
	}
	for(int j=1;j<=num[6];j++){
		cout<<6;
	}
	for(int j=1;j<=num[5];j++){
		cout<<5;
	}
	for(int j=1;j<=num[4];j++){
		cout<<4;
	}
	for(int j=1;j<=num[3];j++){
		cout<<3;
	}
	for(int j=1;j<=num[2];j++){
		cout<<2;
	}
	for(int j=1;j<=num[1];j++){
		cout<<1;
	}
	for(int j=1;j<=num[0];j++){
		cout<<0;
	}
	return 0;
}
