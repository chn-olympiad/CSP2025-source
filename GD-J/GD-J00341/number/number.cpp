#include<bits/stdc++.h>
using namespace std;
int h[1000010];
int i=1;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s1;
	cin >>s1;
	for(int j=0; j<=s1.size()-1; j++) {
		if(s1[j]>='0'&&s1[j]<='9') {
			h[i]=int(s1[j]);
//			cout <<i<<" "<<s1[j]<<" "<<h[i]<<endl;
			i++;
		}

	}
//	for(int j=1; j<=i; j++) {
//		cout <<h[j]<<" ";
//	}
//	cout <<endl;
	sort(h+1,h+1+i);
//	for(int j=1; j<=i; j++) {
//		cout <<h[j]<<" ";
//	}
//	cout <<endl<<i<<endl;
	for(int j=i; j>=1; j--) {
		cout <<char(h[j]);
	}
	return 0;
}
