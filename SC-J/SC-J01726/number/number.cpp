#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	unsigned long long a[s.size()],count=0;
	for(long long i=0;i<s.size();i++){
		if(isdigit(s[i])){
			a[count]=int(s[i]-'0');
			count++;
		}
	}
	sort(a,a+count,greater<int>());
	for(long long i=0;i<count;i++){
		cout<<a[i];
	}
	return 0;
}