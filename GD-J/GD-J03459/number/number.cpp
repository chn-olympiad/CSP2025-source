#include<bits/stdc++.h>
using namespace std;
string s;
char a[1000008];
int x;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			x++;
			a[x]=s[i];
		}
	}
	sort(a+1,a+x+1);
	for(int i=x;i>=1;i--) cout<<a[i];
} 
