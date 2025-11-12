#include <bits/stdc++.h>
using namespace std;

string s;
const int N=1000006;
char a[N];

bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(isdigit(s[i])){
			a[i]=s[i];
		}
	}
	sort(a,a+len,cmp);
	for(int i=0;i<len;i++){
		if(a[i]>='0'&&a[i]<='9'){
			cout << int(a[i]-'0');
		}
	}

	return 0;
}
