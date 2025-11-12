#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b) {
	return a>b;
}
int main(){
	freopen("F:\number\number.in","w",stdin);
	freopen("F:\number\number.out","s",stdout);
	string n;
	int num[114514],c=0;
	cin >> n;
	for (int i=0;i<n.length();i++) if (n[i]>='0' && n[i]<='9') {
		num[c]=n[i]-'0';
		c++;
	}
	sort(num+0,num+c,cmp);
	for (int i=0;i<c;i++) cout << num[i];
}