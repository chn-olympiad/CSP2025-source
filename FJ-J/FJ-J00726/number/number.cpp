#include<bits/stdc++.h>
using namespace std;
string s;
int n,a[2000001],m;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	m=s.size();
	for(int i=0;i<m;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[++n]=s[i]-'0';
		}
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}//ATLETICO MADRID
