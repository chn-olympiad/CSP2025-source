#include<bits/stdc++.h>
using namespace std;
string s;
int q[1010];
int x;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(int(s[i])>=48&&int(s[i])<=57){
			q[x]=int(s[i])-48;
			x++;
		}
	}
	sort(q,q+x);
	for(int i=x-1;i>=0;i--){
		cout<<q[i];
	}
	return 0;
}
