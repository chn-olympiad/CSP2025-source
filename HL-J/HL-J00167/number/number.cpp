#include<bits/stdc++.h>
using namespace std;
const long long N = 3e5;
long long  a[N],b[N],ans = 0;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long l = s.size(),cnt = 0;
	for (int i = 0;i < l;i++){
		if ((((int)s[i])>=48) && (((int)s[i])<=57)){
			a[ans] = (int)s[i];
			cnt++;
			ans++;
		}
	}
	sort(a,a+cnt);
	for (int i =cnt-1;i>=0;i--){
		cout<<(char)a[i];
	}
	return 0;
}
