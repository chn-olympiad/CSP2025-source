#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	if(a > b){
		return true; 
	}else if(a < b){
		return false;
	}
}
int main() {
	//	freopen("number.in","r",stdin);
	//	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	if(s.size() == 1 and s[0] >= '1' and s[0] <= '9'){
		cout << s;
		return 0;
	}
	int c = 0;
	for(int i = 0;i < s.size();i++){
		if(s[i] >= '1' and s[i] <= '9'){
			c ++ ;
		}
	}
	//	cout << c << endl;
	int a[c];
	for(int i = 0;i < s.size();i++){
		if(s[i] >= '1' and s[i] <= '9'){
			a[i] = s[i];
		}
	}
	sort(a , a + c , cmp);
	int num;
	if(c == 2){
		num = a[1] + a[0]*10;
	}else if(c == 3){
		num = a[2] + a[1]*10 + a[0]*100;
	}else if(c == 4){
		num = a[3] + a[2]*10 + a[1]*100 + a[0]*1000;
	}else if(c == 5){
	    num = a[4] + a[3]*10 + a[2]*100 + a[1]*1000 + a[0]*10000;
	}else if(c == 6){
		num = a[5] + a[4]*10 + a[3]*100 + a[2]*1000 + a[1]*10000 + a[0]*100000;
	}else if(c == 7){
		num = a[6] + a[5]*10 + a[4]*100 + a[3]*1000 + a[2]*10000 + a[1]*100000 + a[0]*1000000;
	}
	cout << num;
	return 0;
}
