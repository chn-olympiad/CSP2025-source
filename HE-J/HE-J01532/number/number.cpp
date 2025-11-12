#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s,a;
int x[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int num=0;
	cin >> s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a+=s[i];
		}
	}
	for(int i=0;i<a.size();i++){
		x[i]=int(a[i])-'0';
		num++;
		//cout << x[i];
	}
	sort(x,x+num);
	for(int i=num;i>=0;i--){
		if(i==num&&x[i]==0){
			continue;
		}
		cout << x[i];
	}
	return 0;
} 
