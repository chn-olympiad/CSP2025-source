#include <bits/stdc++.h>
using namespace std;
string s;
int a[1110100]={},l,ii=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i+=1){
		if(s[i]>='0'&&s[i]<='9'){
			a[ii]=s[i]-'0';
			ii+=1;
		}	
	}
	sort(a+1,a+ii);
	for(int i=ii-1;i>=1;i-=1){
		cout<<a[i];
	}
	return 0;
}

