#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
long long ct=0;
int a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++ct]=s[i]-'0';
		}
	}
	sort(a,a+ct+1);
	for(int i=ct;i>=1;i--){
		printf("%d",a[i]);
	}
	return 0;
} 
