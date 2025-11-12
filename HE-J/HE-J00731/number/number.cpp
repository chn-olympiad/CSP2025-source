#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1e6;
ll n=0,a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	ll len=s.size()-1;
	for(ll i=0;i<=len;i++){
		if(s[i]<='9'&&s[i]>='0'){
			n++;
			a[n]=s[i]-'0';
		}
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
