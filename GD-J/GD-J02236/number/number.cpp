#include<bits/stdc++.h>
using namespace std;
int a[1000005];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int w=1;
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0' and s[i]<='9'){
			a[w]=s[i]-'0';
			w++;
		}
	}
	sort(a,a+w+1);
	for(int i=w;i>1;i--){
		cout<<a[i];
	}
	return 0;
} 
