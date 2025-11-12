#include <bits/stdc++.h>

using namespace std;

int b[1000010];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin >> a;
	int t=0;
	for(int i=0;i<a.length();i++){
		if(a[i]<'a'){
			b[t]=a[i]-'0';
			t++;
		}
	}
	sort(b,b+t,cmp);
	for(int i=0;i<t;i++){
		cout << b[i];
	}
	return 0;
}