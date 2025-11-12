#include<bits/stdc++.h>
using namespace std;
const int N=1e6+20;
int a[N],n=0;
int main(){
	//freopen("number4.in","r",stdin);
	//freopen("number4.out","w",stdout);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[++n]=s[i]-'0';
		}
	}
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=n;i++) cout<<a[i];
	return 0;
}
