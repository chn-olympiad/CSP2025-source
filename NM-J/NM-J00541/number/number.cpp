#include<bits/stdc++.h>
using namespace std;
struct p{
	int ans,b;
}a[1000005];
bool cmp(p x,p y){
	return x.ans>y.ans;
	}
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n = s.size();
	for(int i=0;i<n;i++){
		if(s[i] >='0' && s[i] <= '9'){
			a[i].ans = s[i]-'0';
			a[i].b = 1;
		}
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++){
		if(a[i].b==1){
			cout<<a[i].ans;
		}
	}
	return 0;
}
