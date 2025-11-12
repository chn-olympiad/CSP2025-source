#include<bits/stdc++.h>
using namespace std;
string s;
long long a[100000];
int cnt = 0;
bool g(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for (int i=0;i<=100000;i++){
		if (s[i]-'0'<=9 && s[i]-'9'>=0){
			a[cnt] = s[i]-'0';
			cnt++;
		}
	}
	sort(a,a+cnt,g);
	for (int j=0;j<cnt;j++){
		cout<<a[j];
	}
	return 0;
}
