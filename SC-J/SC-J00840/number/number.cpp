#include<bits/stdc++.h>
using namespace std;
long long a[1000000+5];
string s;
int m=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size()-1;i++){
		if(s[i]-'0'<10&&s[i]-'0'>=0){
			a[m]=s[i]-'0';
			m++;
		}
	}
	int n=m-1;
	sort(a+1,a+n+1);
	for(int i=n;i>0;i--){
		cout<<a[i];
	}
	return 0;
}
