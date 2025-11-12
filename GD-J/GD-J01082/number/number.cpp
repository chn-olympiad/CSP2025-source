#include<bits/stdc++.h>
using namespace std;
const int N=1e8+105;
string s;
long long a[N],c=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[c]=(int)s[i]-'0';
			c++;
		}
	}
	sort(a+1,a+1+c);
	for(int i=c;i>=1;i--){
		cout<<a[i];
	}
}
