#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
bool cmp(const int &x,const int &y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++n]=s[i]-48;
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		cout<<a[i];
	}
	return 0;
}
