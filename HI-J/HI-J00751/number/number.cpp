#include<bits/stdc++.h>
using namespace std;
string s;
char c[1000001],a[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++){
		c[i]+=s[i];
		if(c[i]>='0'&&c[i]<='9'){
			a[i]+=c[i];
		}
	}
	sort(a,a+s.size());
	for(int i=s.size()-1;i>=0;i--){
		cout<<a[i];
	} 
	return 0;
}
