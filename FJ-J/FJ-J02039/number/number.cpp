#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N],l,n;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++n]=s[i]-'0';
		}
	}
	sort(a+1,a+1+n);
	if(a[n]==0){
		cout<<0;
		return 0;
	}
	for(int i=n;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
