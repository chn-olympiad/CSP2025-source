#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6;
string s;
int a[N+5];
ll cnt=1,sum=0,cnt1=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	if(s.size()==1){
		cout<<s;
		return 0;
	}
	for(ll i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[cnt1]=s[i]-'0';
			cnt1++;
			cnt*=10;
		}
	}
	sort(a,a+cnt1);
	for(ll i=cnt1-1;i>=0;i--){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
