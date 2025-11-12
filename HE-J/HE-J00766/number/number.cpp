#include <bits/stdc++.h>
using namespace std;
string a;
int b[1000005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> a;
	int s=a.size(),p=0;
	for (int i=0;i<s;i++){
		if(a[i]>='0'&&a[i]<='9'){
			p++;
			b[p]=a[i]-'0';
		}
	}
	sort(b+1,b+p+1,cmp);
	for (int i=1;i<=p;i++){
		cout << b[i];
	}
	return 0;
}
