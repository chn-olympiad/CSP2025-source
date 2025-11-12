#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
char a[N];
int n,len=0;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	s=' '+s;
	for(int i=1;i<=n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++len]=s[i];
		}
	}
	sort(a+1,a+len+1);
	for(int i=len;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}