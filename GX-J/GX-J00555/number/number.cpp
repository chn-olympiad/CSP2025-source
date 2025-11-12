#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int x;
	cin>>s;
	for(int i=1;i<=s.size();i++){
		if(s[i]>=48&&s[i]<=57){
			a[x]==s[i];
			x++;
		}
	}
	sort(a+1,a+x);
	for(int i=x;i>=1;i--){
		cout<<a[i];
	}
return 0;
}
