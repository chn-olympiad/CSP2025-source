//李昊霖，GZ-S00229，观山湖区铭苑
#include<bits/stdc++.h>
using namespace std;
int n,a,b,c;
int s[400][400];
int ma=INT_MIN,cnt;
int main () {
	cin >>n;
	while (n--) {
		int b;
		cin >>b;
		for(int i=1; i<=3; i++) {
			for(int j=1; j<=b; j++) {
				cin >>s[i][j];
			}
		}
		for(int i=1; i<=b; i++) {
			for(int j=1; j<=3; j++) {
			if(ma<s[i][j]){
				ma=s[i][j];
			}
		}
		cnt+=ma;
		ma=INT_MIN;
	}
	cout<<cnt<<'\n';
}
	return 0;
}
