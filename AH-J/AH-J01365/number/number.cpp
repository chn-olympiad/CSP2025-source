#include<bits/stdc++.h>
using namespace std;

string s;
long long w,a[10000005],t,l;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	t=s.size();
	for(int i=0;i<t;i++){
		if((s[i]>='0')&&(s[i]<='9')){
			a[w]=s[i]-'0';
			w++;
		}
	}
	sort(a,a+w);
	for(int i=w-1;i>=0;i--){
		cout << a[i];
	}
	//cout << c;
	return 0;
}
