#include <bits/stdc++.h>
using namespace std;
int a[1000001];
bool cmp(int sb,int sr){
	return sb>sr;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int n=0,m=0;
	cin >> s;
	n=s.size();
	for (int i=0;i<n;i++){
		if(int(s[i])>=48 && int(s[i])<=57){
			a[m]=int(s[i])-48;
			m++;
		}
	}
	sort(a,a+m,cmp);
	for(int i=0;i<m;i++){
		cout << a[i];
	}
	return 0;
}
