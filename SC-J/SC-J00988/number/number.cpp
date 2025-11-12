#include<bits/stdc++.h>
using namespace std;
string a,b,c;
long long maax=-99999,o;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b+=a[i];
		}
	}
	for(int i=0;i<b.size();i++){
		for(int j=0;j<=b.size()-i;j++){
			if(maax<b[j]-'0'){
				maax=b[j]-'0';
				o=j;
			}
		}
		c+=maax+'0';
		b[o]=b[b.size()-i];
		maax=0;
	}
	for(int i=0;i<c.size();i++){
		cout<<c[i];
	}
	return 0;
}