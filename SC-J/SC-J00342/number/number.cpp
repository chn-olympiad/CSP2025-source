#include<bits/stdc++.h>
using namespace std;
const int N=100006;
int shuzi(char x){
	for(int i='0';i<='9';i++){
		if(x==i){
			return i-48;
		}
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int ans=1;
	int a[N];
	string s;
	cin>>s;
	for(int i=1;i<=s.size()+1;i++){
		a[i]=0x3f;
	}
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[ans]=shuzi(s[i]);
			ans++;
		}
	}
	sort(a+1,a+1+s.size());
	for(int i=s.size();i>=1;i--){
		if(a[i]!=0x3f){
			cout<<a[i]; 
		}
	}
	return 0;
}