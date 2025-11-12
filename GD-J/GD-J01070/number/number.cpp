#include<bits/stdc++.h>
using namespace std;

int a[10086],x=1;
int main(){
	string s;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	s = ' '+s;
	for(int i=1;i<=s.size()-1;i++){
		if('0' <= s[i] and s[i] <= '9'){
			a[x] = s[i] - '0';
			x++;
		}
	}
	sort(a+1,a+x);
	for(int i=x-1;i>=1;i--) cout<<a[i];
	return 0;
} 
