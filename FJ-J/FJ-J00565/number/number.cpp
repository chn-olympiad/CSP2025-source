#include<bits/stdc++.h>
using namespace std; 
long long a[15];
string s;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	std::ios::sync_with_stdio(true);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	long long h=0;
	while(h<=s.length()){
		if(s[h]=='0') a[0]++;
		if(s[h]=='1') a[1]++;
		if(s[h]=='2') a[2]++;
		if(s[h]=='3') a[3]++;
		if(s[h]=='4') a[4]++;
		if(s[h]=='5') a[5]++;
		if(s[h]=='6') a[6]++;
		if(s[h]=='7') a[7]++;
		if(s[h]=='8') a[8]++;
		if(s[h]=='9') a[9]++;
		h++;
	}
	int i=9;
	while(i>=0){
		if(a[i]>0){
			cout<<i;
			a[i]--; 
			i++;
		}
		i--;
	}
	
	return 0;
}
