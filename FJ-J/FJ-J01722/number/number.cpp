#include<iostream>
#include<cstring>
#include<iomanip>
#include<algorithm>
using namespace std;typedef int t;typedef long long ll;
string s;ll a[1000086],p;
bool cmb(t x,t b){
	return x>b;
}
t main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(t i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[p]=s[i]-'0';p++;
		}
	}sort(a,a+p,cmb);
	for(t i=0;i<p;i++)printf("%d",a[i]);
	return 0;
}
