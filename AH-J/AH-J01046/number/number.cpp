#include<bits/stdc++.h>
using namespace std;
string s;
char c;
int a[1000010],da=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<1e6;i++){
		c=s[i];
		s+='*';
		if(c>='0'&&c<='9'){
			da++;
			a[da]=s[i]-'0';
		}
		if(c=='*'){
			break;
		}
	}
	sort(a+1,a+da+1,greater<int>());
	for(int i=1;i<=da;i++){
		cout<<a[i];
	}
	return 0;	
}
