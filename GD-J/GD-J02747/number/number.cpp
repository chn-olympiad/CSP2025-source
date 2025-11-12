#include<bits/stdc++.h>
using namespace std;
string s;
const int MAX_N=1e6+5;
int a[MAX_N],km;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')a[++km]=s[i]-'0';
	}
	sort(a+1,a+km+1);
	for(int i=km;i>=1;i--){
		cout<<a[i];
	}
	return 0;
} 
