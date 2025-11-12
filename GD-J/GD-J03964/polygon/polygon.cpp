#include<bits/stdc++.h>
using namespace std;
int a[5000004],s[5000004];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int q;
	for(int i=1;i<=n;i++){
		cin>>q;
	}
	int p;
	for(int i=3;i<=n+2;i++){
		p=i-2;
		while(p>0){
			a[i]+=p;
			p--;
		}
		s[i]=a[i]+s[i-1];
	}
	cout<<s[n];
	return 0;
} 
