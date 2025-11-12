 #include <bits/stdc++.h>
 using namespace std;
 char a[10000001];
 int main(){
 	freopen("number.in","r",stdin);
 	freopen("number.out","w",stdout);
 	string s;
 	cin>>s;
 	long long n;
 	for(long long i=0;i<s.length();i++){
 		if(s[i]>='0' && s[i]<='9') a[i]=s[i];
 		if(a[i]!=' ') n++;
	 }
	sort(a,a+n);
 	for(long long i=n;i>=0;i--){
 		cout<<a[i];
	 }
 	return 0;
 }
