#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long x[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a=0,s1=s.size();
	for(int i=0;i<s1;i++){
		if(s[i]>='0'&&s[i]<='9'){
			x[a]=s[i]-'0';
			a++;
		}
	}
	sort(x,x+a);
	for(int i=a-1;i>=0;i--){
		cout<<x[i];
	}
	return 0;
}
