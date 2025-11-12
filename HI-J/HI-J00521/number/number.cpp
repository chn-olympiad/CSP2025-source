#include <bits/stdc++.h>
using namespace std;
int a[1005] = {0};
long long ans = 0;int n = 0;
int main(){
	freopen("number1.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin>>s;
	int tmp = 0;
	int len = s.size();
	for(int i=0;i<len;i++){
		tmp = s[i] -'0';
		if(tmp>=0 and tmp<=9) {
		    a[n] = tmp;
		    n++;
		}
	}
	sort(a,a+n,greater<int>());
	for(int i=0;i<n;i++){
		ans*=10;
		ans+=a[i];
	}
	cout<<ans;
	return 0; 
}
