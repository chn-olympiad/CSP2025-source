#include<bits/stdc++.h>
using namespace std;
using LL = long long;
LL a[1000010];
bool cmp(const LL &x,const LL &y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	LL t=1;
	for(LL i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[t++]=(s[i]-'0');
		}
	}
	t--;
	sort(a+1,a+t+1,cmp);
	for(LL i=1;i<=t;i++){
		cout<<a[i];
	}
	return 0;
}
