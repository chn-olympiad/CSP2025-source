#include<bits/stdc++.h>
using namespace std;
string s;
int a[1500000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	s="0"+s;
	int x=1;
	for(int i=1;i<=s.length()-1;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[x]=s[i]-'0';
			x++;
		}
	}
	sort(a+1,a+x+1);
	for(int i=x;i>1;i--){
		cout<<a[i];
	}
	return 0;
} 
