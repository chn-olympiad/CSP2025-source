#include<bits/stdc++.h>
using namespace std;
int a[1000005];
string n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size();
	int g=0;
	for(int i=0;i<l;i++){
		if(s[i]>='0' && s[i]<='9'){
			g++;
			a[g]=s[i]-'0';
		}
	}
	sort(a+1,a+1+g);
	for(int i=g;i>=1;i--){
		n+=a[i]+'0';
	}
	cout<<n;
	return 0;
} 
