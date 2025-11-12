#include <bits/stdc++.h>
using namespace std;
string s;
int a[100010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	int x=0;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[x]=s[i]-'0' ;
			x+=1;
		}
	}
	sort(a,a+x);
	for(int i=x-1;i>=0;i--){
		cout<<a[i];
	}
	
	return 0;
} 
