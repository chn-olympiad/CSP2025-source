#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
ll a[N];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	ll l=s.size(),cnt=0;
	for(int i=0;i<l;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[++cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+1+cnt);
	for(int i=cnt;i>=1;i--){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

