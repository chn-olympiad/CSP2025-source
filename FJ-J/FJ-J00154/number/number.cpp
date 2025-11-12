#include <bits/stdc++.h>
using namespace std;
const int N=1e7+5;
int a[N],k=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[k]=s[i]-'0';
			k++;
		}
	}
	sort(a+1,a+k);
	for(int i=k-1;i>=1;i--) cout<<a[i];
	return 0;
}
