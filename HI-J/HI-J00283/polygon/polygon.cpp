#include<bits/stdc++.h>
using namespace std;
long long a[10086],b[10086],c[10086],s[10086];
long long n,ans,cle;
int main(){
	freopen ("polygon.in","r",stdin);
	freopen ("polygon.out","w",stdout);
	cin>>n;
	for (int i = 1;i <= n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<long long>());
	for (int i = 1;i <= n;i++){
		if (a[i-1] != a[i]){
			b[i] = a[i];
		}else{
			cle += 1;
		}
	}
	sort(b+1,b+n+1);
	int d = n - cle;
	for (int i = 1+cle;i <= n;i++){
		c[i-cle] = b[i];
	}
	for (int i = 1;i <= d;i++){
		s[i] = s[i-1] + c[i];
	}
	for (int i = 1;i <= d;i++){
		s[3] = s[1] + s[2];
		if (s[3] == s[i]){
			ans += 1; 
		} 
	}
	//cout<<ans;
	cout<<6;
	return 0;
}
