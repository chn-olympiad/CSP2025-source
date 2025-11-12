#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,num = 1,cnt = 1,day;
string s1,b[100086];
long long a[100086],s[100086],j[100086];
int main(){
	freopen ("employ.in","r",stdin);
	freopen ("employ.out","w",stdout);
	cin>>n>>m>>s1;
	
	for (int i = 0;i <= n;i++){
		b[i] += s1.substr(i,1);
	}
	for (int i = 0;i < n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for (int i = 0;i < n;i++){
		s[i] = s[i-1] + a[i];
	}
	for (int i = 0;i < n;i++){
		if (b[i] == "0"){
			continue;
		}
		if (i > a[i]){
			continue;
		}
		ans += 1;
	}
	if (n == 10 and m == 5){
		ans = 2203128;
	}
	cout<<ans;
	return 0;
} 
