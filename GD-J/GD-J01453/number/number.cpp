#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
const int N=1e6+15; 
string s;
int a[N],tot;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') a[++tot]=s[i]-'0';
	}
	sort(a+1,a+tot+1);
	for(int i=tot;i>=1;i--) cout<<a[i];
	return 0;
} 
