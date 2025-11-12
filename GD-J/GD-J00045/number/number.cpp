#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],p;
string s;
int main(){
	freopen("number.in","w",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[++p]=s[i]-'0';
		}
	}
	sort(a+1,a+p+1,greater<int>());
	for(int i=1;i<=p;i++){
		cout<<a[i];
	}
	return 0;
} 
