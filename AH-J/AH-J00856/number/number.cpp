#include <bits/stdc++.h>
using namespace std;
long long a[10];
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int e=s.size();
	for(int i=0;i<e;i++){
		if(s[i]=='0') a[0]++;
		if(s[i]=='1') a[1]++;
		if(s[i]=='2') a[2]++;
		if(s[i]=='3') a[3]++;
		if(s[i]=='4') a[4]++;
		if(s[i]=='5') a[5]++;
		if(s[i]=='6') a[6]++;
		if(s[i]=='7') a[7]++;
		if(s[i]=='8') a[8]++;
		if(s[i]=='9') a[9]++;
	}
	while(a[9]){
		printf("9");
		a[9]--;
	}
	while(a[8]){
		printf("8");
		a[8]--;
	}
	while(a[7]){
		printf("7");
		a[7]--;
	}
	while(a[6]){
		printf("6");
		a[6]--;
	}
	while(a[5]){
		printf("5");
		a[5]--;
	}
	while(a[4]){
		printf("4");
		a[4]--;
	}
	while(a[3]){
		printf("3");
		a[3]--;
	}
	while(a[2]){
		printf("2");
		a[2]--;
	}
	while(a[1]){
		printf("1");
		a[1]--;
	}
	while(a[0]){
		printf("0");
		a[0]--;
	}
	return 0;
}
