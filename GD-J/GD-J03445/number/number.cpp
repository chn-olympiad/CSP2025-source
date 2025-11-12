#include <bits/stdc++.h>
using namespace std;
string a;
int t[1000010],s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0' && a[i]<='9'){
			t[++s]=(a[i]-'0');
		}
	}
	sort(t+1,t+s+1,greater<int>());
	for(int i=1;i<=s;i++){
		cout<<t[i];
	}
	return 0;
}
