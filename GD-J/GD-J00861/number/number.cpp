#include <bits/stdc++.h>
using namespace std;
string s;
char ch[1000005];
int n,sum;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	s=' '+s;
	for(int i=1;i<=n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			ch[++sum]=s[i];
		}
	}
	sort(ch+1,ch+sum+1);
	for(int i=sum;i>=1;i--){
		cout<<ch[i];
	}
	return 0;
}
