#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin >> a;
	short s[N]={0};
	int p =0;
	
	for(int i = 0;i<a.size();i++){
		if(a[i]>='0' && a[i]<='9'){
			int q=(a[i]-'0');
			s[p]=q;
			p++;
		}
	}
	sort(s,s+p,cmp);
	for(int i = 0;i<p;i++) cout << s[i];
	return 0;
}
