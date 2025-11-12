#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+12;
ll cnt=0,a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	ll le=s.size();
	for (int i=0;i<le;i++){
		if (s[i]>='0'&&s[i]<='9'){
			a[++cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+1+cnt,cmp);
	for (int i=1;i<=cnt;i++){
		cout<<a[i];
	}
	return 0;
} 
