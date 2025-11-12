#include <bits/stdc++.h>
using namespace std;
string d
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>d;
	
	int n=0;
	while(s){
		n++; 
	}
	int m=0;
	for(int i=1;i<=n;i++){
		if(s[i]<10 && s[i]>0){
			a[i]=s[i];
			m++;
		}
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=m;i++){
		g+=a[i]+a[i+1];
	}
	cout<<g;
} 
