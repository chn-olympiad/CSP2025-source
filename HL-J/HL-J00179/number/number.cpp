#include<bits/stdc++.h>
using namespace std;
string s;
char c[1000010];
long long a=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			c[a]=s[i];
			a++;
		}
	}
	sort(c,c+a);
	for(int i=a-1;i>=1;i--){
		cout<<c[i];
	}
	return 0;
}