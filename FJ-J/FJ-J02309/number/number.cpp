#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],sum=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n=1;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='1'&&s[i]<='9'){
		 	a[1]=s[i]-'0';
			n++;
		}
	}
	n-=1;
	sort(a,a+n);
	for(int i=n;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
