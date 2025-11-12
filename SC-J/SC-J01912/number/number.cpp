#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000005];//ans[1000005],
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int b=s.size(),c=1;
	for(int i=0;i<b;i++){
		if(s[i]-'0'<=9&&s[i]-'0'>=0){
			a[c]=s[i]-'0';
			c++;
//			cout<<1;
		}
	}
	sort(a+1,a+1+c);
//	cout<<c<<" "<<b<<" ";
	for(int i=c;i>1;i--){
		cout<<a[i];
	}
	return 0;
}