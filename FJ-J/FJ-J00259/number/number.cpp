#include<bits/stdc++.h>
using namespace std;
int a[1000005],n;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int x = s.size();
	for (int i = 0;i <= x;i++){
		if (s[i]>='0'&&s[i]<='9'){
			a[++n]=s[i]-'0';
		}
	}
	if (n!=1){
		sort(a+1,a+n,cmp);
		if (a[1]==0){
			cout << 0;
			return 0;
		}
		for (int i = 1;i <= n;i++){
			cout << a[i];
		}
	}else{
		cout << 0;
	}
	return 0;
}
