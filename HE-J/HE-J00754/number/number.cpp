#include<bits/stdc++.h>
using namespace std;
string s,c;
int a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' and s[i]<='9'){
			c+=s[i];
		}
	}
	for(int i=0;i<c.size();i++){
		a[i]=c[i]-'0';
	}
	int v=c.size();
	sort(a,a+v);
	for(int i=v-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
} 
