#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,a,e;
	char c[10];
	int d=0;
	cin>>s;
	d=s.size();
	if(d=1){
		cout<<s;
	}
	if(d>1){
		for(int i=1;i<=d;i++){
			if(s[i]>=48&&s[i]<=57){
				a[i]=int(s[i]);
			}
		}
		for(int i=1;i<=d;i++){
			c[1]=max(a[i],a[i+1]);
			a[i]=a[i+1];
			a[i+1]=c[1];
	
		}
		for(int i=1;i<=d;i++){
			cout<<char(a[i]);
		}
	}	
	return 0;
} 
