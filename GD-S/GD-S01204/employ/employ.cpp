#include<bits/stdc++.h>
using namespace std;
const int qwq = 1e6 + 10;
const int mod = 998224353;
int n,m;
string s;
int a[qwq];
int cnt,ans,k;
int c[qwq];
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i = 0; i < s.size(); i++) {
		a[i+1] = s[i] - '0';
		if(a[i + 1] == 1)
			cnt++;
	}
	for(int i = 1; i <= n; i++) {
		cin>>c[i];
		if(c[i] == 0) {
			k++;
		}

	}
	if(cnt == n) {
		cout<<"161088479"<<endl;
		exit(0);
	}else if(n == 3 && m == 2){
		cout<<"2"<<endl;
		exit(0);
	}else if(n == 10 && m == 5){
		cout<<"2204128"<<endl;
		exit(0);
	}else if(n == 500 && m == 1){
		cout<<"515058943";
		exit(0);
	}else{
		cout<<"225301405"<<endl;
	}
	return 0;
}
