#include<bits/stdc++.h>
using namespace std;
int a[20];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	memset(a,0,sizeof(a));
	for(int i=0; i<s.length(); i++) {
		if(s[i]=='1') {
			a[1]++;
			continue;
		} else {
			if(s[i]=='0') {
				a[0]++;
				continue;
			}
			if(s[i]=='2') {
				a[2]++;
				continue;
			}
			if(s[i]=='3') {
				a[3]++;
				continue;
			}
			if(s[i]=='4') {
				a[4]++;
				continue;
			}
			if(s[i]=='5') {
				a[5]++;
				continue;
			}
			if(s[i]=='6') {
				a[6]++;
				continue;
			}
			if(s[i]=='7') {
				a[7]++;
				continue;
			}
			if(s[i]=='8') {
				a[8]++;
				continue;
			}
			if(s[i]=='9') {
				a[9]++;
				continue;
			}
		}
	}
	for(int i=9; i>=0; i--) {
		for(int j=1;j<=a[i];j++)
		{
			cout<<i;
		}
	}
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
