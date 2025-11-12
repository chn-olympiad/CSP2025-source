#include <bits/stdc++.h>
using namespace std;

string s;
long long a[1000010],n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(long long i=0,len=s.size();i<len;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[++n]=s[i]-'0';
		}
	}
	stable_sort(a+1,a+1+n,greater<long long>());
	for(long long i=1;i<=n;i++){
		cout << a[i];
	}
	return 0;
}
