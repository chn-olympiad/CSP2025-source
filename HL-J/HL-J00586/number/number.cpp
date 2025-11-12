#include<bits/stdc++.h>
using namespace std;
const int n=1e6+5;
int a[n];
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int t=0;
	for(int i=0;i<=s.size();i++){
		if(s.size()==1 && s[i]>='0' && s[i]<='9'){
			cout<<s[i];
			return 0;
		}
		if(s[i]>='0' && s[i]<='9'){
			t++;
			a[n]+=s[i];
		}
	}
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	cout<<a[n];
	return 0;
} 
