#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],m;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.length();
	for(int i=0;i<n;i++){
		if('0'<=s[i]&&s[i]<='9'){
			m++;
			a[m]=s[i]-'0';
		}
	}
	sort(a+1,a+1+m);
	for(int i=m;i>=1;i--)cout<<a[i];
	cout<<endl;
	return 0;
}
