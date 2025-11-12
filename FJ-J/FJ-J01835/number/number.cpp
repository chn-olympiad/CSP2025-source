#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000001],b=1,l;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.length();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[b]=s[i]-'0';
			b++;
		}
	}
	b--;
	sort(a+1,a+b+1);
	for(int i=b;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
